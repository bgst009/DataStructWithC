//
// Created by bgst on 2020/8/29.
//

#include "test.h"
#include "SortTestHelper/SortTestHelper.h"

int main() {

//    testIS();
    testIS_3();
    return 0;
}

void testSS() {
    srand(time(NULL));
    ElementType element;
    ElementType array[1000];
    for (int i = 0; i < 1000; i++) {
        element = rand() % 1000 + 1;
        array[i] = element;
    }


    SelectionSort(array, 1000);

    if (isSort(array, 1000))
        printf("\nSelectionSort sorted \n");
}

void testIS() {
    srand(time(NULL));
    ElementType element;
    ElementType array[10];
    for (int i = 0; i < 10; i++) {
        element = rand() % 1000 + 1;
        array[i] = element;
    }

    InsertionSort(array, 10);
    show(array, 10);
    if (isSort(array, 10))
        printf("\n InsertionSort sorted \n");
    else
        printf("\n sort failed \n");
}

void testIS_2() {
    srand(time(NULL));
    clock_t start, finish;
    double duration;
    ElementType element;
    ElementType array[100000];
    for (int i = 0; i < 100000; i++) {
        element = rand() % 100000 + 1;
        array[i] = element;
    }

    start = clock();
    InsertionSortWithoutExchange(array, 100000);
    finish = clock();
    duration = (double) (finish - start) / CLOCKS_PER_SEC;
    printf(" %f seconds\n", duration);

//    show(array, 1000);
    if (isSort(array, 100000))
        printf("\n InsertionSortWithoutExchange sorted \n");
    else
        printf("\n sort failed \n");
}

void testIS_3() {
    int size = 100000;
    ElementType *array = generateRandomArray(size, 1, 100000);
    ElementType *array2 = copyIntArray(array, size);

    char *name = "InsertionSortWithoutExchange";
    char *name2 = "InsertionSort";
    testSort(name, InsertionSortWithoutExchange, array, size);
    testSort(name2, InsertionSort, array2, size);
}


