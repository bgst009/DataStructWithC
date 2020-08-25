//
// Created by bgst on 2020/8/25.
//

#ifndef DATASTRUCTWITHC_SQQUEUE_H
#define DATASTRUCTWITHC_SQQUEUE_H

#include "../header.h"

typedef int QElemType;

typedef struct {
    //初始化的动态分配存储空间
    QElemType *base;
    //头指针，指向队头元素
    int front;
    //尾指针，指向最后一个元素的下一个位置
    int rear;
} SqQueue;


/**
 * 初始化顺序栈
 * @param sqQueue
 * @return 初始化成功 true
 */
bool InitQueue_SQ(SqQueue *sqQueue);

/**
 * 销毁顺序栈
 * @param sqQueue
 * @return 销毁成功 true
 */
bool DestroyQueue_SQ(SqQueue *sqQueue);

/**
 * 清空顺序栈
 * @param sqQueue
 * @return 清空成功 true
 */
bool ClearQueue_SQ(SqQueue *sqQueue);

/**
 * 顺序栈是否为空
 * @param sqQueue
 * @return 空 true
 */
bool QueueEmpty_SQ(SqQueue *sqQueue);

/**
 * 入队
 * @param sqQueue
 * @param elem 入队元素值
 * @return
 */
bool EnQueue_SQ(SqQueue *sqQueue, QElemType elem);

/**
 * 出队
 * @param sqQueue
 * @param elem 出队元素值
 * @return
 */
bool DeQueue_SQ(SqQueue *sqQueue, QElemType *elem);

/**
 * 获取队头
 * @param sqQueue
 * @param elem 队头元素值
 * @return
 */
bool GetHead_SQ(SqQueue *sqQueue, QElemType *elem);

/**
 * 返回队长
 * @param sqQueue
 * @return 队长
 */
int QueueLength_SQ(SqQueue *sqQueue);

/**
 * 打印顺序队
 * @param linkQueue
 * @return
 */
bool print_SQ(SqQueue *sqQueue);

#endif //DATASTRUCTWITHC_SQQUEUE_H
