all: main test

CXX = clang++
override CXXFLAGS += -g -Wall -Werror

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' ! -name '*test.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)
TEST_SRCS = $(shell find tests -type f -name '*.test.cpp' -print | sed -e 's/ /\\ /g')

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
	NIX_HARDENING_ENABLE= $(CXX) $(CXXFLAGS) -O0 $(SRCS) -o "$@"

test: $(SRCS) $(TEST_SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) $(SRCS) -o test
	./test

clean:
	rm -f main main-debug test
