FROM gcc:12.2.0

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y \
    clang \
    make \
    && rm -rf /var/lib/apt/lists/* \
    && apt-get clean \
    && if [ -f Makefile ]; then make test; else echo "Makefile not found"; fi
