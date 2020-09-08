//
// Created by bgst on 2020/8/25.
//

#include "SqQueue.h"
/**
 * 初始化顺序栈
 * @param sqQueue
 * @return 初始化成功 true
 */
bool InitQueue_SQ(SqQueue *sqQueue) {
    sqQueue->base = (QElemType *) malloc(MAXQSIZE * sizeof(QElemType));
    if (!sqQueue->base) {
        printf("\n 没有足够大的空间 \n");
        return false;
    }
    sqQueue->front = sqQueue->rear = 0;
    return true;
}

/**
 * 销毁顺序栈
 * @param sqQueue
 * @return 销毁成功 true
 */
bool DestroyQueue_SQ(SqQueue *sqQueue) {
    free(sqQueue->base);
    sqQueue->base = NULL;
    sqQueue->front = sqQueue->rear = 0;
    return true;
}

/**
 * 清空顺序栈
 * @param sqQueue
 * @return 清空成功 true
 */
bool ClearQueue_SQ(SqQueue *sqQueue) {
    sqQueue->front = sqQueue->rear = 0;
    return true;
}

/**
 * 顺序栈是否为空
 * @param sqQueue
 * @return 空 true
 */
bool QueueEmpty_SQ(SqQueue *sqQueue) {
    //判空条件为 头尾指针相等
    return (sqQueue->front == sqQueue->rear) ? true : false;
}

/**
 * 入队
 * @param sqQueue
 * @param elem 入队元素值
 * @return
 */
bool EnQueue_SQ(SqQueue *sqQueue, QElemType elem) {
    //队列满？
    if (sqQueue->front == ((sqQueue->rear + 1) % MAXQSIZE)) {
        printf("\n 队列已经满 \n");
        return false;
    }

    sqQueue->base[sqQueue->rear] = elem;
    sqQueue->rear = (sqQueue->rear + 1) % MAXQSIZE;

    return true;
}

/**
 * 出队
 * @param sqQueue
 * @param elem 出队元素值
 * @return
 */
bool DeQueue_SQ(SqQueue *sqQueue, QElemType *elem) {

    //队空？
    if (QueueEmpty_SQ(sqQueue)) {
        printf("\n Queue is Empty!!! \n");
        return false;
    }

    *elem = sqQueue->base[sqQueue->front];
    sqQueue->front = (sqQueue->front + 1) % MAXQSIZE;
    return true;
}

/**
 * 获取队头
 * @param sqQueue
 * @param elem 队头元素值
 * @return
 */
bool GetHead_SQ(SqQueue *sqQueue, QElemType *elem) {
    //队空？
    if (QueueEmpty_SQ(sqQueue)) {
        printf("\n Queue is Empty!!! \n");
        return false;
    }

    *elem = sqQueue->base[sqQueue->front];
    return true;
}

/**
 * 返回队长
 * @param sqQueue
 * @return 队长
 */
int QueueLength_SQ(SqQueue *sqQueue) {
    return (sqQueue->rear - sqQueue->rear + MAXQSIZE) % MAXQSIZE;
}

/**
 * 打印顺序队
 * @param linkQueue
 * @return
 */
bool print_SQ(SqQueue *sqQueue) {
    if (!sqQueue->base) {
        printf("\n Queue not exist!!! \n");
        return false;
    }

    if (QueueEmpty_SQ(sqQueue)) {
        printf("\n Queue is Empty!!! \n");
        return false;
    }

    QElemType elem;

    while (!QueueEmpty_SQ(sqQueue)) {
        DeQueue_SQ(sqQueue, &elem);
        printf(" %d ", elem);
    }

    printf("\n\n");

    return true;
}