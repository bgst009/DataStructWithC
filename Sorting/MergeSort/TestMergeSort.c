//
// Created by bgst on 2020/8/30.
//

#include "Helper.h"
#include "MergeSort.h"

int main() {

    int size = 10000000;
    ElementType *arr = generateRandomArray(size, 1, 1000);
    ElementType *arr2 = copyIntArray(arr, size);
    testSort("MS", MS, arr, size);
    testSort("MS2",MS2, arr2, size);

    free(arr);

    return 0;
}
