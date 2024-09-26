#include "../include/bogo.sort.h"
#include "./catch2/catch.hpp"

TEST_CASE("Тесты BogoSort") {
  int N = 5;

  SECTION("Массив целых чисел") {
    int Array[5] = {3, 1, 4, 1, 5};
    bogoSort(Array, N);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] <= Array[i + 1]);
    }
  }

  SECTION("Пустой массив целых чисел") {
    int Array2[0] = {};
    bogoSort(Array2, 0);
    // Тестирование пустого массива
    REQUIRE(true); // Пустой массив считается отсортированным
  }

  SECTION("Массив чисел с плавающей запятой") {
    double Array3[5] = {2.3, 5.0, -1.0, 8.0, -20.0};
    bogoSort(Array3, N);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array3[i] <= Array3[i + 1]);
    }
  }
}
