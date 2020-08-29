//
// Created by bgst on 2020/8/29.
//

#include "test.h"
#include "SortTestHelper/SortTestHelper.h"

int main() {

    testSS_IS();
    return 0;
}

void testSS_IS() {
//    int size = 1000000;
//    ElementType *array = generateNearlyOrderedArray(size, 500);
//    ElementType *array2 = copyIntArray(array, size);
//
//    char *name = "InsertionSortWithoutExchange";
//    char *name2 = "InsertionSort";
//    testSort(name, InsertionSortWithoutExchange, array, size);
//    testSort(name2, InsertionSort, array2, size);

    int size = 10;
    ElementType *array = generateRandomArray(size, 1, 1000);
    ElementType *array2 = copyIntArray(array, size);
    char *name = "ShellShortWithoutExchange";
    char *name2 = "ShellShort";
    printArray(array, size);
    testSort(name2, ShellShort, array2, size);
    printArray(array2, size);
    testSort(name, ShellShortWithoutExchange, array, size);
    printArray(array, size);

}