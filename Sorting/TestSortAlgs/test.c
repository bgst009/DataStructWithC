//
// Created by bgst on 2020/8/29.
//

#include "test.h"

#include "../InsertionSort/InsertionSort.h"
#include "../SelectionSort/SelectionSort.h"
#include "SortTestHelper.h"

int main() {

    testSelectionSort_InsertionSort_NearlyRandom();
    return 0;
}

void testSelectionSort_InsertionSort_NearlyRandom() {
    int size = 100000;
    ElementType* arr = generateNearlyOrderedArray(size, 50);
    ElementType* arr2 = copyIntArray(arr, size);
    testSort("InsertionSort", InsertionSort, arr, size);
    testSort("SelectionSort", SelectionSort, arr2, size);
}
