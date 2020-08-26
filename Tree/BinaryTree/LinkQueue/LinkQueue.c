//
// Created by bgst on 2020/8/25.
//

#include "./LinkQueue.h"

bool InitQueue_LQ(LinkQueue *linkQueue) {
    QNode *headNode = (QueuePtr) malloc(sizeof(QNode));
    if (!headNode)
        return false;
    headNode->next = NULL;
    linkQueue->front = linkQueue->rear = headNode;

    linkQueue->length = 0;
}

bool DestroyQueue_LQ(LinkQueue *linkQueue) {
    while (linkQueue->front) {
        linkQueue->rear = linkQueue->front->next;
        free(linkQueue->front);
        linkQueue->front = linkQueue->rear;
    }
    linkQueue->length = 0;
    return false;
}

bool ClearQueue_LQ(LinkQueue *linkQueue) {
    QNode *tmp_node;
    while (linkQueue->front->next) {
        tmp_node = linkQueue->front->next;
        linkQueue->front->next = tmp_node->next;
        free(tmp_node);
    }

    linkQueue->length = 0;
    return true;
}

bool QueueEmpty_LQ(LinkQueue *linkStack) {
    return linkStack->front->next ? false : true;
}

bool EnQueue_LQ(LinkQueue *linkQueue, QElemType elem) {
    QNode *new_node = (QueuePtr) malloc(sizeof(QNode));
    if (new_node) {
        new_node->next = NULL;
        new_node->data = elem;
        linkQueue->rear->next = new_node;
        linkQueue->rear = new_node;

        linkQueue->length++;
        return true;
    } else {
        return false;
    }
}

bool DeQueue_LQ(LinkQueue *linkQueue, QElemType *elem) {
    if (QueueEmpty_LQ(linkQueue)) {
        printf("\n Queue is empty \n");
        return false;
    }
    //临时存贮被删除的节点
    QNode *tmp_node;
    tmp_node = linkQueue->front->next;
    *elem = tmp_node->data;
    linkQueue->front->next = tmp_node->next;

    //如果是删除最后一个元素，尾指针==头指针
    if (linkQueue->rear == tmp_node)
        linkQueue->rear = linkQueue->front;

    free(tmp_node);


    linkQueue->length--;
    return true;

}


bool GetHead_LQ(LinkQueue *linkQueue, QElemType *elem) {
    if (QueueEmpty_LQ(linkQueue)) {
        printf("\n Queue is empty \n");
        return false;
    }

    *elem = linkQueue->front->next->data;
    return true;
}

int QueueLength_LQ(LinkQueue *linkQueue) {
    return linkQueue->length;
}

bool print_LQ(LinkQueue *linkQueue) {
    if (linkQueue->front == NULL) {
        printf("\n Queue not exist \n");
        return false;
    }

    if (QueueEmpty_LQ(linkQueue)) {
        printf("\n Queue is empty \n");
        return false;
    }

    QElemType elem;
    while (linkQueue->front->next) {
        DeQueue_LQ(linkQueue, &elem);
        printf(" %d ", elem);
    }
    printf("\n\n");
}