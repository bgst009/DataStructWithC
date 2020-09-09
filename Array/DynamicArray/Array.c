//
// Created by bgst on 2020/9/9.
//

#include "Array.h"

#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct MyArray {
    ElementType* data;
    int size;
    int number;
};
Array initArray(int size) {
    Array array;
    array.data = (ElementType*) malloc(sizeof(ElementType) * size);
    memset(array.data, 0, sizeof(ElementType) * size);
    array.size = size;
    array.number = 0;
    return array;
}
void getElement(Array array, int number, ElementType* element) {
    if (number > array.number)
        return;
    *element = array.data[number];
}
void addElement(Array* array, ElementType element) {
    if (array->number < array->size) {
        array->data[array->number++] = element;
    } else {
        array->data = (ElementType*) realloc(array->data, sizeof(ElementType) * INCREMENT);
        array->data[array->number++] = element;
        array->size += INCREMENT;
    }
}
void traverseArray(Array array) {
    printf("\n");
    for (int i = 0; i < array.number; ++i) {
        printf(" %d ", array.data[i]);
    }
    printf("\n");
}

int main() {

    int size = 0;
    Array array = initArray(size);

    srand(time(NULL));
    for (int i = 0; i < size + 5; ++i) {
        addElement(&array, rand() % 100 + 1);
    }

    traverseArray(array);


    return 0;
}
