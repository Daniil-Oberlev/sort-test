# Документация по функции `binaryInsertionSort`

## Описание

Функция `binaryInsertionSort` сортирует массив с помощью алгоритма `сортировки вставками`, используя бинарный поиск для определения позиции вставки.

## Шаблон функции

```cpp
template <typename T>
void binaryInsertionSort(T *arr, int n, bool ascending = true);
```

## Параметры

- `arr:` Указатель на массив элементов типа `T`, который нужно отсортировать.
- `n:` Размер массива (количество элементов в массиве).
- `ascending:` Булевый параметр, указывающий порядок сортировки.
  - Если `true` (по умолчанию), массив сортируется по возрастанию.
  - Если `false`, массив сортируется по убыванию.

## Пример использования

```cpp
#include "binaryInsertion.sort.h"

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Сортировка по возрастанию
    binaryInsertionSort(arr, n, true);

    // Вывод отсортированного массива
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    return 0;
}
```

## Алгоритм работы

1. Для каждого элемента, начиная со второго, алгоритм находит позицию, куда его можно вставить, используя бинарный поиск.
2. Элементы, которые находятся на позиции вставки и после неё, сдвигаются вправо для освобождения места.
3. Вставляет текущий элемент на найденную позицию.
4. Процесс продолжается для всех элементов массива.

## Вспомогательная функция

### binarySearch

```cpp
template <typename T>
int binarySearch(T *arr, T item, int low, int high, bool ascending = true);
```

- `Описание:` Находит позицию вставки элемента `item` в отсортированном массиве `arr` с использованием бинарного поиска.
- `Параметры:`
  - `arr:` Указатель на отсортированный массив типа `T`.
  - `item:` Элемент, который нужно вставить.
  - `low:` Начальный индекс диапазона поиска.
  - `high:` Конечный индекс диапазона поиска.
  - `ascending:` Булевый параметр для определения порядка сортировки.

## Примечения

- Бинарная сортировка вставками более эффективна, чем обычная сортировка вставками, особенно для больших массивов.
- Временная сложность составляет O(n log n) в среднем случае, но O(n^2) в худшем случае при использовании вставок.
