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
    ElementType* arrInsertionSort = generateNearlyOrderedArray(size, 50);
    ElementType* arrSelectionSort = copyIntArray(arrInsertionSort, size);
    testSort("InsertionSort", InsertionSort, arrInsertionSort, size);
    testSort("SelectionSort", SelectionSort, arrSelectionSort, size);
}
