//
// Created by bgst on 2020/9/11.
//

#ifndef ARRAY_DYNAMICQUEUE_H
#define ARRAY_DYNAMICQUEUE_H

#include "./Array.h"

typedef Array Queue;
typedef ArrayElementType QueueElementType;
Queue cstl_queue_initQueue(int capacity);
int cstl_queue_getLength(Queue queue);
bool cstl_queue_isEmpty(Queue queue);
int cstl_queue_capacity(Queue queue);
void cstl_queue_enqueue(Queue* queue, QueueElementType element);
QueueElementType cstl_queue_dequeue(Queue* queue);
void cstl_queue_print(Queue queue);

#endif//ARRAY_DYNAMICQUEUE_H
