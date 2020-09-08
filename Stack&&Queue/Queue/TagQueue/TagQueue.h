//
// Created by bgst on 2020/9/8.
//

#ifndef SQ_TAGQUEUE_H
#define SQ_TAGQUEUE_H

#include <stdbool.h>
typedef struct tagQueue TQ;
typedef int TQElement;

TQ* initTQ(int size);
bool enQueueTQueue(TQ* queue, TQElement element);
TQElement deQueueTQueue(TQ* queue);
void traverseTQueue(TQ* queue);
bool isEmptyTQueue(TQ* queue);
bool isFullTQueue(TQ* queue);


#endif//SQ_TAGQUEUE_H
