//
// Created by bgst on 2020/8/29.
//

#ifndef DATASTRUCTWITHC_INSERTIONSORT_H
#define DATASTRUCTWITHC_INSERTIONSORT_H

#include "../header.h"

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

#endif //DATASTRUCTWITHC_INSERTIONSORT_H
