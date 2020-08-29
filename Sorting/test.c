//
// Created by bgst on 2020/8/29.
//

#include "test.h"

int main() {

    testSS();
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
