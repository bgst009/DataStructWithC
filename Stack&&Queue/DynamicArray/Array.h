//
// Created by bgst on 2020/9/9.
//

#ifndef DATASTRUCTWITHC_ARRAY_H
#define DATASTRUCTWITHC_ARRAY_H
#include <stdbool.h>
#define INCREMENT 20

typedef struct Array Array;
typedef int ArrayElementType;


/**
 * 初始化固定大小的数组
 * @param capacity
 * @return 数组
 */
Array cstl_array_initArray(int capacity);
/**
 * 获取索引位置的元素
 * @param array 数组
 * @param index 索引
 * @param element 元素指针
 */
void cstl_array_getElement(Array array, int index, ArrayElementType* element);
ArrayElementType cstl_array_getLast(Array array);
/**
 * 修改index位置的元素
 * @param array pointer to array
 * @param index 索引
 * @param element 元素
 */
void cstl_array_setElement(Array* array, int index, ArrayElementType element);
/**
 * 在索引位置处添加一个元素
 * @param array 数组指针
 * @param index 索引
 * @param element 元素
 */
void cstl_array_addElement(Array* array, int index, ArrayElementType element);
/**
 * 在所有元素后添加一个元素
 * @param array 数组指针
 * @param element 元素
 */
void cstl_array_addLast(Array* array, ArrayElementType element);
/**
 * 在所有元素前添加一个元素
 * @param array 数组指针
 * @param element 元素
 */
void cstl_array_addFirst(Array* array, ArrayElementType element);
/**
 * 获取数组的容量
 * @param array 数组
 * @return 容量
 */
int cstl_array_getCapacity(Array array);
/**
 * 获取数组中的元素个数
 * @param array 数组
 * @return 个数
 */
int cstl_array_getLength(Array array);
/**
 * 返回数组是否为空
 * @param array 数组
 * @return if empty array return true else return false
 */
bool cstl_array_isEmpty(Array array);
/**
 * 查找数组中是否有元素element
 * @param array 数组
 * @param element 元素
 * @return
 */
bool cstl_array_containsElement(Array array, ArrayElementType element);
/**
 * 查找数组中元素element所在的索引，如果不存在元素e，则返回-1
 * @param array 数组
 * @param element 元素
 * @return index of element in array
 */
int cstl_array_findElement(Array array, ArrayElementType element);
/**
 * 从数组中删除index位置的元素, 返回删除的元素
 * @param array
 * @param index
 * @return
 */
int cstl_array_removeElementWithIndex(Array* array, int index);
/**
 * 从数组中删除第一个元素, 返回删除的元素
 * @param array 数组指针
 * @param index 索引
 * @return 被删除元素
 */
int cstl_array_removeFirst(Array* array);
/**
 * 从数组中删除最后一个元素, 返回删除的元素
 * @param array 数组指针
 * @param index 索引
 * @return 被删除元素
 */
int cstl_array_removeLast(Array* array);
/**
 * 从数组中删除元素element
 * @param array 数组指针
 * @param element 删除元素
 */
void cstl_array_removeElement(Array* array, ArrayElementType element);
/**
 * 答应数组
 * @param array 数组
 */
void printArray(Array array);


#endif//DATASTRUCTWITHC_ARRAY_H
