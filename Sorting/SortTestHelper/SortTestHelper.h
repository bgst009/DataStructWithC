//
// Created by bgst on 2020/8/29.
//

#ifndef DATASTRUCTWITHC_SORTTESTHELPER_H
#define DATASTRUCTWITHC_SORTTESTHELPER_H

#include "../header.h"

// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
ElementType *generateRandomArray(int n, int rangeL, int rangeR) {

//    assert(rangeL <= rangeR);


    ElementType *arr = (ElementType *) malloc(sizeof(ElementType) * n);

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

    ElementType *arr = (ElementType *) malloc(sizeof(ElementType) * n);

    for (int i = 0; i < n; i++)
        arr[i] = i;

    srand(time(NULL));
    for (int i = 0; i < swapTimes; i++) {
        int posx = rand() % n;
        int posy = rand() % n;
        exchange(arr,posx,posy);
    }

    return arr;
}

// 拷贝整型数组a中的所有元素到一个新的数组, 并返回新的数组
ElementType *copyIntArray(ElementType *a, int n) {

    ElementType *arr = (ElementType *) malloc(sizeof(ElementType) * n);

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

// 判断arr数组是否有序
bool isSorted(const ElementType arr[], int n) {

    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;

    return true;
}

// 测试sort排序算法排序arr数组所得到结果的正确性和算法运行时间
// * 使用VS编码的同学, 对于函数指针的写法和调用方法可能和课程中介绍的有所不同;
// * 并且不同版本的VS, 其具体语法可能也有差异, 这是因为VS的编译器不完全是按照C++的标准实现的;
// * 本课程按照C++11的标准进行书写。对于VS编译器带来的语法差异, 希望同学们可以自己在网上查找相关资料解决;
// * 大家也可以在课程的官方QQ群中交流
// * 另外, 使用函数指针本身并不是这个课程的重点, 大家也完全可以使用自己的方式书写代码, 最终只要能够测试出自己书写的算法的效率即可
// * 推荐大家阅读我在问答区向大家分享的一个学习心得: 【学习心得分享】请大家抓大放小，不要纠结于C++语言的语法细节
// * 链接: http://coding.imooc.com/learn/questiondetail/4100.html

void testSort(char *sortName,
              bool (*sort)(ElementType[], int),
              ElementType arr[],
              int n
) {

    clock_t startTime = clock();
    sort(arr, n);
    clock_t endTime = clock();

    if (isSort(arr, n))
        printf("\n %s sorted \n", sortName);
    else
        printf("\n sort failed \n");


    printf(" %s : %lu s \n", sortName, ((endTime
                                         - startTime) / CLOCKS_PER_SEC));

    return;
}


#endif //DATASTRUCTWITHC_SORTTESTHELPER_H
