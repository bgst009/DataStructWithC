//
// Created by bgst on 2020/8/29.
//

#include "InsertionSort.h"
#include "../SortTestHelper/Template.h"

bool InsertionSort(ElementType *array, int length) {
    //参数合法性判断
    if (array == NULL || length <= 0) {
        printf("\n ERROR \n");
        return false;
    }

    //array[i...length) 未被排序 array[0,i) 已经排好序
    //j [1,i]
    int i, j;
    for (i = 1; i < length; i++) {
        for (j = i; j > 0; j--) {
            //找前面大的
            if (array[j - 1] > array[j])
                exchange(array, j, j - 1);
            else break;
        }
    }

    return true;
}

bool InsertionSortWithoutExchange(ElementType *array, int length) {
    //参数合法性判断
    if (array == NULL || length <= 0) {
        printf("\n ERROR \n");
        return false;
    }

    //array[i...length) 未被排序 array[0,i) 已经排好序
    //j [1,j]
    int i, j;
    for (i = 1; i < length; i++) {
        ElementType element = array[i];
        for (j = i; j > 0; j--) {
            //找前面大的
            if (array[j - 1] > element)
                array[j] = array[j - 1];
            else break;
        }

        array[j] = element;
    }

    return true;


}
