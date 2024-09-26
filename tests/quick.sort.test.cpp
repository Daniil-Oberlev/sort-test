#include "../include/quick.sort.h"
#include "../lib/catch2/catch.hpp"
#include <vector>

TEST_CASE("Тесты быстрой сортировки") {
  int N = 5;

  SECTION("Массив целых чисел по возрастанию") {
    int Array[5] = {2, 6, 5, 3, 9};
    quickSort(Array, 0, N - 1);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] <= Array[i + 1]);
    }
  }

  SECTION("Пустой массив целых чисел по возрастанию") {
    int Array2[0] = {};
    quickSort(Array2, 0, 0);
  }

  SECTION("Массив чисел с плавающей запятой по возрастанию") {
    double Array3[5] = {2.3, 5.0, -1.0, 8.0, -20.0};
    quickSort(Array3, 0, N - 1);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array3[i] <= Array3[i + 1]);
    }
  }

  SECTION("Массив целых чисел по убыванию") {
    int Array[5] = {2, 6, 5, 3, 9};
    quickSort(Array, 0, N - 1, false);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] >= Array[i + 1]);
    }
  }

  SECTION("Массив чисел с плавающей запятой по убыванию") {
    double Array3[5] = {2.3, 5.0, -1.0, 8.0, -20.0};
    quickSort(Array3, 0, N - 1, false);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array3[i] >= Array3[i + 1]);
    }
  }

  SECTION("Массив из одного элемента") {
    int Array[1] = {42};
    quickSort(Array, 0, 0);
    REQUIRE(Array[0] == 42);
  }

  SECTION("Массив с дубликатами по возрастанию") {
    int Array[5] = {5, 3, 5, 1, 3};
    quickSort(Array, 0, N - 1);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] <= Array[i + 1]);
    }
  }

  SECTION("Массив с уже отсортированными элементами по возрастанию") {
    int Array[5] = {1, 2, 3, 4, 5};
    quickSort(Array, 0, N - 1);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] <= Array[i + 1]);
    }
  }

  SECTION("Массив с одинаковыми элементами") {
    int Array[5] = {5, 5, 5, 5, 5};
    quickSort(Array, 0, N - 1);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] == Array[i + 1]);
    }
  }

  SECTION("Массив с отрицательными числами по возрастанию") {
    int Array[5] = {-3, -1, -7, -5, -2};
    quickSort(Array, 0, N - 1);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] <= Array[i + 1]);
    }
  }

  SECTION("Очень большой массив по возрастанию") {
    int largeN = 100000;
    std::vector<int> LargeArray(largeN);

    for (int i = 0; i < largeN; ++i) {
      LargeArray[i] = largeN - i;
    }

    quickSort(LargeArray.data(), 0, largeN - 1);

    for (int i = 0; i < largeN - 1; i++) {
      REQUIRE(LargeArray[i] <= LargeArray[i + 1]);
    }
  }
}
