#!/bin/bash

# Удаляем предыдущий файл с ошибками, если он существует
rm -f errors.log

echo "Форматирование файлов..."

# Объединяем команды find для поиска всех файлов
find . \( -name "*.h" -o -name "*.hpp" -o -name "*.cpp" \) -exec clang-format -i {} \; 2>> errors.log

# Проверяем, есть ли ошибки
if [ -s errors.log ]; then
    echo "Ошибки при форматировании:"
    cat errors.log
else
    echo "Форматирование завершено без ошибок."
fi
