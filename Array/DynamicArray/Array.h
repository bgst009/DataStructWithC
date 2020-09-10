//
// Created by bgst on 2020/9/9.
//

#ifndef DATASTRUCTWITHC_ARRAY_H
#define DATASTRUCTWITHC_ARRAY_H
#include <stdbool.h>
#define INCREMENT 20

typedef struct MyArray Array;
typedef int ElementType;


/**
 * 初始化固定大小的数组
 * @param capacity
 * @return 数组
 */
Array initArray(int capacity);
/**
 * 获取索引位置的元素
 * @param array 数组
 * @param index 索引
 * @param element 元素指针
 */
void getElement(Array array, int index, ElementType* element);
/**
 * 修改index位置的元素
 * @param array pointer to array
 * @param index 索引
 * @param element 元素
 */
void setElement(Array* array, int index, ElementType element);
/**
 * 在索引位置处添加一个元素
 * @param array 数组指针
 * @param index 索引
 * @param element 元素
 */
void addElement(Array* array, int index, ElementType element);
/**
 * 在所有元素后添加一个元素
 * @param array 数组指针
 * @param element 元素
 */
void addLast(Array* array, ElementType element);
/**
 * 在所有元素前添加一个元素
 * @param array 数组指针
 * @param element 元素
 */
void addFirst(Array* array, ElementType element);

/**
 * 获取数组的容量
 * @param array 数组
 * @return 容量
 */
int getCapacity(Array array);
/**
 * 获取数组中的元素个数
 * @param array 数组
 * @return 个数
 */
int getLength(Array array);
/**
 * 返回数组是否为空
 * @param array 数组
 * @return if empty array return true else return false
 */
bool isEmpty(Array array);

/**
 * 查找数组中是否有元素element
 * @param array 数组
 * @param element 元素
 * @return
 */
bool containsElement(Array array, ElementType element);

/**
 * 查找数组中元素element所在的索引，如果不存在元素e，则返回-1
 * @param array 数组
 * @param element 元素
 * @return index of element in array
 */
int findElement(Array array, ElementType element);

/**
 * 从数组中删除index位置的元素, 返回删除的元素
 * @param array
 * @param index
 * @return
 */
int removeElementWithIndex(Array* array, int index);

int removeFirst(Array* array, int index);
int removeLast(Array* array, int index);
void removeElement(Array* array, ElementType element);


void printArray(Array array);


#endif//DATASTRUCTWITHC_ARRAY_H
