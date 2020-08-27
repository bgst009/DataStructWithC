//
// Created by bgst on 2020/8/25.
//

#ifndef DATASTRUCTWITHC_LINKQUEUE_H
#define DATASTRUCTWITHC_LINKQUEUE_H

#include "../TreeNode.h"

typedef BiTNode* QElemType;


typedef struct QuNode {
    QElemType data;
    struct QuNode *next;
} QNode, *QueuePtr;
typedef struct {
    //头指针
    QueuePtr front;
    //尾指针
    QueuePtr rear;
    //队长
    int length;
} LinkQueue;

/**
 * 初始化链队
 * @param linkQueue
 * @return
 */
bool InitQueue_LQ(LinkQueue *linkQueue);

/**
 * 销毁链队
 * @param linkQueue
 * @return
 */
bool DestroyQueue_LQ(LinkQueue *linkQueue);

/**
 * 清空链队
 * @param linkQueue
 * @return
 */
bool ClearQueue_LQ(LinkQueue *linkQueue);

/**
 * 判断链队是否为空
 * @param linkStack
 * @return 空 true
 */
bool QueueEmpty_LQ(LinkQueue *linkStack);

/**
 * 入队
 * @param linkQueue
 * @param elem
 * @return
 */
bool EnQueue_LQ(LinkQueue *linkQueue, QElemType elem);

/**
 * 出队
 * @param linkQueue
 * @param elem
 * @return
 */
bool DeQueue_LQ(LinkQueue *linkQueue, QElemType *elem);

/**
 * 若链队不为空用elem返回队头
 * @param linkQueue
 * @param elem
 * @return 队头元素
 */
bool GetHead_LQ(LinkQueue *linkQueue, QElemType *elem);

/**
 * 返回队列长度
 * @param linkQueue
 * @return
 */
int QueueLength_LQ(LinkQueue *linkQueue);

/**
 * 打印链队
 * @param linkQueue
 * @return
 */
bool print_LQ(LinkQueue *linkQueue);

#endif //DATASTRUCTWITHC_LINKQUEUE_H
