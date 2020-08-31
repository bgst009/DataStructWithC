//
// Created by bgst on 2020/8/29.
//

#ifndef DATASTRUCTWITHC_INSERTIONSORT_H
#define DATASTRUCTWITHC_INSERTIONSORT_H

#include "header.h"

/**
 *
 * @param array unsorted array
 * @param length array size
 * @return boolean true if sorted successfully;
 */
bool InsertionSort(ElementType *array, int length);

/**
 *
 * @param array unsorted array
 * @param length array size
 * @return boolean true if sorted successfully;
 */
bool InsertionSortWithoutExchange(ElementType *array, int length);

/**
 * 在 array中对 [l..r]区间内进行插入排序
 * @param array
 * @param l 左边界
 * @param r 右边界
 * @return
 */
bool InsertionSortInRange(ElementType *array, int l, int r);

#endif//DATASTRUCTWITHC_INSERTIONSORT_H
