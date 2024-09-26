#include "../include/shell.sort.h"
#include "../lib/catch2/catch.hpp"

TEST_CASE("Тесты сортировки Шелла") {
  int N = 5;

  SECTION("Массив целых чисел по возрастанию") {
    int Array[5] = {2, 6, 5, 3, 9};
    shellSort(Array, N);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] <= Array[i + 1]);
    }
  }

  SECTION("Пустой массив целых чисел по возрастанию") {
    int Array2[5] = {};
    shellSort(Array2, N);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array2[i] <= Array2[i + 1]);
    }
  }

  SECTION("Массив чисел с плавающей запятой по возрастанию") {
    double Array3[5] = {2.3, 5.0, -1.0, 8.0, -20.0};
    shellSort(Array3, N);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array3[i] <= Array3[i + 1]);
    }
  }

  SECTION("Массив целых чисел по убыванию") {
    int Array[5] = {2, 6, 5, 3, 9};
    shellSort(Array, N, false);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] >= Array[i + 1]);
    }
  }

  SECTION("Массив чисел с плавающей запятой по убыванию") {
    double Array3[5] = {2.3, 5.0, -1.0, 8.0, -20.0};
    shellSort(Array3, N, false);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array3[i] >= Array3[i + 1]);
    }
  }

  SECTION("Массив из одного элемента") {
    int Array[1] = {42};
    shellSort(Array, 1);
    REQUIRE(Array[0] == 42);
  }

  SECTION("Массив с дубликатами по возрастанию") {
    int Array[5] = {5, 3, 5, 1, 3};
    shellSort(Array, N);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] <= Array[i + 1]);
    }
  }
}
