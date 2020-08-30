//
// Created by bgst on 2020/8/30.
//

#ifndef SELECTIONSORT_HELPER_H
#define SELECTIONSORT_HELPER_H
#include "header.h"

/**
 * 交换数组中的元素
 *
 * @param array 数组
 * @param i 元素下标
 * @param j 元素下标
 * @return boolean true if successful
 */
bool exchange(ElementType *array, int i, int j) {

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


// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
ElementType *generateRandomArray(int n, int rangeL, int rangeR) {

  //    assert(rangeL <= rangeR);

  ElementType *arr = (ElementType *)malloc(sizeof(ElementType) * n);

  srand(time(NULL));
  for (int i = 0; i < n; i++)
    arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
  return arr;
}

// 生成一个近乎有序的数组
// 首先生成一个含有[0...n-1]的完全有序数组, 之后随机交换swapTimes对数据
// swapTimes定义了数组的无序程度:
// swapTimes == 0 时, 数组完全有序
// swapTimes 越大, 数组越趋向于无序
ElementType *generateNearlyOrderedArray(int n, int swapTimes) {

  ElementType *arr = (ElementType *)malloc(sizeof(ElementType) * n);

  for (int i = 0; i < n; i++)
    arr[i] = i;

  srand(time(NULL));
  for (int i = 0; i < swapTimes; i++) {
    int posx = rand() % n;
    int posy = rand() % n;
    exchange(arr, posx, posy);
  }

  return arr;
}

// 拷贝整型数组a中的所有元素到一个新的数组, 并返回新的数组
ElementType *copyIntArray(ElementType *a, int n) {

  ElementType *arr = (ElementType *)malloc(sizeof(ElementType) * n);

  for (int i = 0; i < n; ++i) {
    arr[i] = a[i];
  }

  return arr;
}

// 打印arr数组的所有内容
void printArray(ElementType arr[], int n) {

  for (int i = 0; i < n; i++)
    printf(" %d ", arr[i]);

  printf("\n");

  return;
}



//// 判断arr数组是否有序
// bool isSorted(const ElementType arr[], int n) {
//
//    for (int i = 0; i < n - 1; i++)
//        if (arr[i] > arr[i + 1])
//            return false;
//
//    return true;
//}

/**
 * 判断数组是否已经有序
 * @param array 数组
 * @param length 数组大小
 * @return boolean true if array is sorted
 */
bool isSort(ElementType *array, int length) {
  //参数合法性判断
  if (array == NULL || length <= 0) {
    printf("\n isSort ERROR \n");
    return false;
  }

  for (int i = 0; i < length - 1; i++)
    if (array[i] > array[i + 1])
      return false;

  return true;
}

// 测试sort排序算法排序arr数组所得到结果的正确性和算法运行时间
void testSort(char *sortName, void (*sort)(ElementType[], int),
              ElementType arr[], int n) {

  clock_t startTime = clock();
  sort(arr, n);
  clock_t endTime = clock();

  if (isSort(arr, n))
    printf("\n %s sorted \n", sortName);
  else
    printf("\n sort failed \n");

  printf(" %s : %lu s \n", sortName, ((endTime - startTime) / CLOCKS_PER_SEC));

  return;
}

#endif // SELECTIONSORT_HELPER_H
