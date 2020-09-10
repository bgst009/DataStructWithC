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
    //数组容量
    int capacity;
    //元素个数
    int length;
};
Array initArray(int capacity) {
    Array array;
    //分配内存
    array.data = (ElementType*) malloc(sizeof(ElementType) * capacity);
    //初始化
    memset(array.data, 0, sizeof(ElementType) * capacity);
    array.capacity = capacity;
    array.length = 0;
    return array;
}
void getElement(Array array, int index, ElementType* element) {
    if (index > array.length)
        return;
    *element = array.data[index];
}

void setElement(Array* array, int index, ElementType element) {
    if (index > array->length)
        return;
    array->data[index] = element;
}
void addElement(Array* array, int index, ElementType element) {
    //参数不合法
    if (index < 0 && index > array->length) {
        printf("\n Add failed. Require index >= 0 and index <= size. \n");
        return;
    }

    //    printf("%d ", element);

    //容量够直接赋值
    if (array->length < array->capacity) {
        for (int i = array->length - 1; i >= index; i--) {
            array->data[i + 1] = array->data[i];
        }
        array->data[index] = element;
        array->length++;
    } else {//不够在分配内存
        array->data = (ElementType*) realloc(array->data, sizeof(ElementType) * INCREMENT);
        for (int i = array->length - 1; i >= index; i--) {
            array->data[i + 1] = array->data[i];
        }
        array->data[index] = element;
        array->capacity += INCREMENT;
        array->length++;
    }
}
void addLast(Array* array, ElementType element) {
    addElement(array, array->length, element);
}
void addFirst(Array* array, ElementType element) {
    addElement(array, 0, element);
}
void printArray(Array array) {
    int i;
    printf("\n [");
    for (i = 0; i < array.length - 1; i++) {
        printf("%d , ", array.data[i]);
    }
    printf("%d]", array.data[i]);
    printf("\n");
}
int getCapacity(Array array) {
    return array.capacity;
}
int getLength(Array array) {
    return array.length;
}
bool isEmpty(Array array) {
    return array.length == 0 ? true : false;
}
bool containsElement(Array array, ElementType element) {
    for (int i = 0; i < array.length; ++i) {
        if (array.data[i] == element)
            return true;
    }
    return false;
}
int findElement(Array array, ElementType element) {
    for (int i = 0; i < array.length; ++i) {
        if (array.data[i] == element) {
            //            printf("%d", i);
            return i;
        }
    }
    return -1;
}
int removeElementWithIndex(Array* array, int index) {
    //参数不合法
    if (index < 0 && index >= array->length) {
        printf("\n Remove failed. Index is illegal. \n");
        return -1;
    }
    int ret = array->data[index];
    for (int i = index + 1; i < array->length; i++) {
        array->data[i - 1] = array->data[i];
    }
    array->length--;
    return ret;
}
int removeFirst(Array* array, int index) {
    removeElementWithIndex(array, 0);
}
int removeLast(Array* array, int index) {
    removeElementWithIndex(array, array->length - 1);
}
void removeElement(Array* array, ElementType element) {
    int index = findElement(*array, element);
    if (index != -1) {
        removeElementWithIndex(array, index);
    }
}

int main() {

    int size = 5;
    Array array = initArray(size);

    //    srand(time(NULL));
    for (int i = 0; i < size + 5; ++i) {
        addLast(&array, i);
    }
    printArray(array);

    addFirst(&array, 10);
    printArray(array);
    addLast(&array, 11);
    printArray(array);

    removeElementWithIndex(&array, 2);
    printArray(array);
    removeElement(&array, 4);
    printArray(array);


    return 0;
}
