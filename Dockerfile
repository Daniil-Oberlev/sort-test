FROM gcc:latest

WORKDIR /app

# Копируем все файлы в контейнер
COPY . .

# Устанавливаем необходимые пакеты для сборки
RUN apt-get update && apt-get install -y \
    clang \
    make \
    && rm -rf /var/lib/apt/lists/*

# Компилируем и запускаем тесты
RUN make test
