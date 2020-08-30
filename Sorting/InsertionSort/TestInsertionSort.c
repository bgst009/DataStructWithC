//
// Created by bgst on 2020/8/30.
//

#include "Helper.h"
#include "InsertionSort.h"

int main() {

    int size = 1000000;
    ElementType *arr = generateRandomArray(size, 1, 1000);
    ElementType *arr2 = generateNearlyOrderedArray(size,500);
    printf("\n RandomArray\n");
    testSort("InsertionSort", InsertionSort, arr, size);

    printf("\n NearlyOrderedArray \n");
    testSort("InsertionSort", InsertionSort, arr2, size);

    free(arr);

    return 0;
}