//
// Created by bgst on 2020/8/29.
//

#include "ShellShort.h"
/**
 * 交换数组中的元素
 *
 * @param array 数组
 * @param i 元素下标
 * @param j 元素下标
 * @return boolean true if successful
 */
bool exch(ElementType *array, int i, int j) {

    //参数合法性判断
    if (array == NULL || i < 0 || j < 0) {
        printf("\n exchange ERROR \n");
        return false;
    }

    ElementType tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;

    return true;
}


bool ShellShort(ElementType *a, int N) {

    //参数合法性判断
    if (a == NULL || N <= 0) {
        printf("\n ShellShort ERROR \n");
        return false;
    }


    int h = 1;
    while (h < N / 3)h = 3 * h + 1;//1,4,13,40

    while (h >= 1) {
        for (int i = h; i < N; ++i) {
            for (int j = i; j >= h && (a[j - h] > a[j]); j -= h) {
                exch(a, j - h, j);
            }
        }
        h = h / 3;
    }

    return true;
}

bool ShellShortWithoutExchange(ElementType *array, int size) {
    //参数合法性判断
    if (array == NULL || size <= 0) {
        printf("\n ShellShort ERROR \n");
        return false;
    }

    int increment = 1;
    int j;
    int i;
    ElementType tmp;

//    while (increment < size / 3) increment = 3 * increment + 1;
//
//    while (increment >= 1) {//划分子序列
//        for (int i = increment; i < size; ++i) {//对每个子序列进行插入排序
//            ElementType element = array[i];
//            //在子序列中找到 element 对应有序的位置
//            for (j = i; j >= increment && (array[j - increment] > element); j -= increment) {
//                array[j] = array[j - increment];
//            }
//            array[j] = element;
//        }
//        increment = increment / 3;
//    }

    ElementType element;
    //划分子序列
    for (increment = (size / 2); increment > 0; increment /= 2) {
        //对每个子序列以 increment 为增量进行插入排序
        for (i = increment; i < size; i++) {
            element = array[i];
            //以 increment 为增量
            for (j = i; j >= increment; j -= increment)
                if (element < array[j - increment])
                    array[j] = array[j - increment];
                else
                    break;
            array[j] = element;
        }
    }

    return true;
}
