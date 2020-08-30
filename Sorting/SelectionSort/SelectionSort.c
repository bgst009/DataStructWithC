//
// Created by bgst on 2020/8/29.
//

#include "SelectionSort.h"

/**
 * 交换数组中的元素
 *
 * @param array 数组
 * @param i 元素下标
 * @param j 元素下标
 * @return boolean true if successful
 */
bool exchSelectionSort(ElementType *array, int i, int j) {

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

bool SelectionSort(ElementType *array, int length) {
  //参数合法性判断
  if (array == NULL || length <= 0) {
    printf("\n ERROR \n");
    return false;
  }

  // array[i...length) 未被排序 array[0,i) 已经排好序
  // array[i...length) 中最小值和 array[i] 交换位置
  int MinIndex;
  for (int i = 0; i < length; ++i) {
    MinIndex = i;
    for (int j = i + 1; j < length; ++j) {
      if (array[j] < array[MinIndex])
        MinIndex = j;
    }
    exchSelectionSort(array, i, MinIndex);
  }

  return true;
}
