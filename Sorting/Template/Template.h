//
// Created by bgst on 2020/8/29.
//

#ifndef DATASTRUCTWITHC_TEMPLATE_H
#define DATASTRUCTWITHC_TEMPLATE_H

#include "../header.h"

/**
 * 交换数组中的元素
 *
 * @param array 数组
 * @param i 元素下标
 * @param j 元素下标
 * @return boolean true if successful
 */
bool exchange(ElementType *array, int i, int j);

/**
 * 判断数组是否已经有序
 * @param array 数组
 * @param length 数组大小
 * @return boolean true if array is sorted
 */
bool isSort(ElementType *array, int length);

/**
 * 打印数组
 * @param array 数组
 * @param length 数组大小
 * @return boolean true if successful
 */
bool show(ElementType *array, int length);

#endif //DATASTRUCTWITHC_TEMPLATE_H
