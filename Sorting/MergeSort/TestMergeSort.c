//
// Created by bgst on 2020/8/30.
//

#include "Helper.h"
#include "MergeSort.h"

int main() {

    int size = 100000000;
    ElementType *arr = generateRandomArray(size, 1, 1000);
    testSort("C_MergeSort", MS, arr, size);

    free(arr);

    return 0;
}
