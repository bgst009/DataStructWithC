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
    ArrayElementType* data;
    //数组容量
    int capacity;
    //元素个数
    int length;
};
Array cstl_array_initArray(int capacity) {
    Array array;
    //分配内存
    array.data = (ArrayElementType*) malloc(sizeof(ArrayElementType) * capacity);
    //初始化
    memset(array.data, 0, sizeof(ArrayElementType) * capacity);
    array.capacity = capacity;
    array.length = 0;
    return array;
}
void cstl_array_getElement(Array array, int index, ArrayElementType* element) {
    if (index > array.length)
        return;
    *element = array.data[index];
}

void cstl_array_setElement(Array* array, int index, ArrayElementType element) {
    if (index > array->length)
        return;
    array->data[index] = element;
}
void cstl_array_addElement(Array* array, int index, ArrayElementType element) {
    //参数不合法
    if (index < 0 || index > array->length) {
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
        array->data = (ArrayElementType*) realloc(array->data, sizeof(ArrayElementType) * INCREMENT);
        for (int i = array->length - 1; i >= index; i--) {
            array->data[i + 1] = array->data[i];
        }
        array->data[index] = element;
        array->capacity += INCREMENT;
        array->length++;
    }
}
void cstl_array_addLast(Array* array, ArrayElementType element) {
    cstl_array_addElement(array, array->length, element);
}
void cstl_array_addFirst(Array* array, ArrayElementType element) {
    cstl_array_addElement(array, 0, element);
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
int cstl_array_getCapacity(Array array) {
    return array.capacity;
}
int cstl_array_getLength(Array array) {
    return array.length;
}
bool cstl_array_isEmpty(Array array) {
    return array.length == 0 ? true : false;
}
bool cstl_array_containsElement(Array array, ArrayElementType element) {
    for (int i = 0; i < array.length; ++i) {
        if (array.data[i] == element)
            return true;
    }
    return false;
}
int cstl_array_findElement(Array array, ArrayElementType element) {
    for (int i = 0; i < array.length; ++i) {
        if (array.data[i] == element) {
            //            printf("%d", i);
            return i;
        }
    }
    return -1;
}
int cstl_array_removeElementWithIndex(Array* array, int index) {
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
int cstl_array_removeFirst(Array* array, int index) {
    cstl_array_removeElementWithIndex(array, 0);
}
int cstl_array_removeLast(Array* array, int index) {
    cstl_array_removeElementWithIndex(array, array->length - 1);
}
void cstl_array_removeElement(Array* array, ArrayElementType element) {
    int index = cstl_array_findElement(*array, element);
    if (index != -1) {
        cstl_array_removeElementWithIndex(array, index);
    }
}

int main() {

    int size = 5;
    Array array = cstl_array_initArray(size);

    //    srand(time(NULL));
    for (int i = 0; i < size + 5; ++i) {
        cstl_array_addLast(&array, i);
    }
    printArray(array);

    cstl_array_addFirst(&array, 10);
    printArray(array);
    cstl_array_addLast(&array, 11);
    printArray(array);

    cstl_array_removeElementWithIndex(&array, 2);
    printArray(array);
    cstl_array_removeElement(&array, 4);
    printArray(array);


    return 0;
}
