//
// Created by bgst on 2020/8/29.
//

#include "test.h"

#include "../InsertionSort/InsertionSort.h"
#include "../MergeSort/MergeSort.h"
#include "../SelectionSort/SelectionSort.h"
#include "../ShellSort/ShellShort.h"
#include "SortTestHelper.h"

int main() {

    testSelectionSort_InsertionSort_NearlyRandom();
    return 0;
}

void testSelectionSort_InsertionSort_NearlyRandom() {
    int size = 50000000;
    ElementType* arrInsertionSort = generateRandomArray(size, 1, size * 5);
    ElementType* arrSelectionSort = copyIntArray(arrInsertionSort, size);
    ElementType* arrShellSort = copyIntArray(arrSelectionSort, size);
    ElementType* arrMergeSort = copyIntArray(arrShellSort, size);
//    testSort("SelectionSort", SelectionSort, arrSelectionSort, size);
//    testSort("InsertionSort", InsertionSortWithoutExchange, arrInsertionSort, size);
    testSort("ShellSort", ShellShortWithoutExchange, arrInsertionSort, size);
    testSort("MergeSort", MS, arrInsertionSort, size);
}
