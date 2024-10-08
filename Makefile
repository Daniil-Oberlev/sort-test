CXX = clang++
override CXXFLAGS += -g -Wall -Werror

BIN_DIR = $(CURDIR)/bin

# Изменения: добавляем фильтрацию для игнорирования файлов в папке benchmarks
SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' ! -name '*test.cpp' ! -name '*benchmark.cpp' ! -path './benchmarks/*' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)
TEST_SRCS = $(shell find tests -type f -name '*.test.cpp' -print | sed -e 's/ /\\ /g')
BENCH_SRCS = $(shell find benchmarks -type f -name '*.benchmark.cpp' -print | sed -e 's/ /\\ /g') benchmarks/benchmark_utils.cpp benchmarks/benchmark.helper.cpp

include config.env

$(shell mkdir -p $(BIN_DIR))

$(CATCH_HEADER):
	@echo "Загрузка заголовка Catch2..."
	mkdir -p $(CATCH_DIR)
	wget -q -O $(CATCH_HEADER) $(CATCH_URL)
	@echo "Catch2 загружен."

$(BENCH_HEADER):
	@echo "Загрузка заголовка Benchmark..."
	mkdir -p $(BENCH_DIR)
	wget -q -O $(BENCH_HEADER) $(BENCH_URL)
	wget -q -O $(BENCH_EXPORT) $(BENCH_EXPORT_URL)
	@echo "Benchmark загружен."

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(BIN_DIR)/main

main-debug: $(SRCS) $(HEADERS)
	NIX_HARDENING_ENABLE= $(CXX) $(CXXFLAGS) -O0 $(SRCS) -o $(BIN_DIR)/main-debug

# Обновление команды test для игнорирования benchmarks
test: $(CATCH_HEADER) $(TEST_SRCS) $(filter-out benchmarks/benchmark.helper.cpp benchmarks/benchmark_utils.cpp, $(SRCS)) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) $(filter-out benchmarks/benchmark.helper.cpp benchmarks/benchmark_utils.cpp, $(SRCS)) -o $(BIN_DIR)/test -lbenchmark -lpthread
	$(BIN_DIR)/test

benchmark: $(BENCH_HEADER) $(BENCH_EXPORT) $(BENCH_SRCS)
	$(CXX) $(CXXFLAGS) $(BENCH_SRCS) -DBENCHMARK_MAIN_ENABLED -o $(BIN_DIR)/benchmark -lbenchmark -lpthread
	$(BIN_DIR)/benchmark

clean:
	rm -f $(BIN_DIR)/main $(BIN_DIR)/main-debug $(BIN_DIR)/test $(BIN_DIR)/benchmark
	rm -rf $(CATCH_DIR) $(BENCH_DIR)

.PHONY: all main main-debug test benchmark clean
