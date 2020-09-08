//
// Created by bgst on 2020/9/8.
//

#ifndef SQ_QUEUEWITHSTACK_H
#define SQ_QUEUEWITHSTACK_H

#include "../../Stack/Sq_Stack/stack.h"
typedef struct QueueWithStack {
    Stack stack1;
    Stack stack2;
} QS;

typedef int QSElement;

QS initQS(int size);
bool isEmptyQS(QS* queue);
bool isFullQS(QS* queue);
QSElement deQueueQS(QS* queue);
bool enQueueQS(QS* queue, QSElement element);
void traverseQS(QS* queue);


#endif//SQ_QUEUEWITHSTACK_H
