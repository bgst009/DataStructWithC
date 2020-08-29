//
// Created by bgst on 2020/8/29.
//

#include "Template.h"

bool exchange(ElementType *array, int i, int j) {

    //参数合法性判断
    if (array == NULL || i < 0 || j < 0) {
        printf("\n ERROR \n");
        return false;
    }

    ElementType tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;

    return true;
}

bool isSort(ElementType *array, int length) {
    //参数合法性判断
    if (array == NULL || length <= 0) {
        printf("\n ERROR \n");
        return false;
    }

    for (int i = 1; i < length; ++i) {
        if (array[i] < array[i - 1]) {
            return false;
        }
    }

    return true;
}

bool show(ElementType *array, int length) {
    //参数合法性判断
    if (array == NULL || length <= 0) {
        printf("\n ERROR \n");
        return false;
    }

    printf("\n");
    for (int i = 0; i < length; ++i) {
        printf(" %d ", array[i]);
    }
    printf("\n");

    return true;
}
