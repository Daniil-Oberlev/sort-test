#include "../include/exchange.sort.h"
#include "./catch2/catch.hpp"

TEST_CASE("Тесты сортировки обменом") {
  int N = 5;

  SECTION("Массив целых чисел по возрастанию") {
    int Array[5] = {2, 6, 5, 3, 9};
    exchangeSort(Array, N);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] <= Array[i + 1]);
    }
  }

  SECTION("Массив целых чисел по убыванию") {
    int Array[5] = {2, 6, 5, 3, 9};
    exchangeSort(Array, N, false);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] >= Array[i + 1]);
    }
  }

  SECTION("Массив чисел с плавающей запятой по возрастанию") {
    double Array[5] = {2.3, 5.0, -1.0, 8.0, -20.0};
    exchangeSort(Array, N);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] <= Array[i + 1]);
    }
  }

  SECTION("Массив чисел с плавающей запятой по убыванию") {
    double Array[5] = {2.3, 5.0, -1.0, 8.0, -20.0};
    exchangeSort(Array, N, false);
    for (int i = 0; i < N - 1; i++) {
      REQUIRE(Array[i] >= Array[i + 1]);
    }
  }
}
