//
// Created by bgst on 2020/9/8.
//

#include "TagQueue.h"

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

struct tagQueue {
    TQElement* data;
    int front, rear;
    int tag;
    int maxSize;
};
TQ initTQ(int size) {
    TQ result;
    result.data = (TQElement*) malloc(sizeof(TQElement) * size);
    result.maxSize = size;
    result.tag = 0;
    result.rear = 0;
    result.front = 0;
    return result;
}
bool enQueueTQueue(TQ* queue, TQElement element) {
    if (isFullTQueue(*queue)) {
        printf("\n Queue is full !!!\n");
        return false;
    }
    queue->data[queue->rear] = element;
    queue->rear = (queue->rear + 1) % queue->maxSize;
    queue->tag = 1;
    return true;
}
TQElement deQueueTQueue(TQ* queue) {
    if (isEmptyTQueue(*queue)) {
        printf("\n Queue is empty !!!\n");
        return -1;
    }
    TQElement result = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->maxSize;
    queue->tag = 0;
    return result;
}
void traverseTQueue(TQ queue) {

    while (!isEmptyTQueue(queue)) {
        printf("%d ", deQueueTQueue(&queue));
    }
}
bool isEmptyTQueue(TQ queue) {
    return (queue.tag == 0 && queue.rear == queue.front) ? true : false;
}
bool isFullTQueue(TQ queue) {
    return (queue.tag == 1 && queue.rear == queue.front) ? true : false;
}

int main() {
    int size = 10;
    TQ queue = initTQ(size);
    for (int i = 0; i < size + 5; ++i) {
        enQueueTQueue(&queue, i);
    }
    for (int i = 0; i < size + 5; ++i) {
        printf("%d ", deQueueTQueue(&queue));
    }
    //    traverseTQueue(queue);

    return 0;
}
