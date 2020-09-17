//
// Created by bgst on 2020/9/11.
//

#include "DynamicQueue.h"

#include <stdio.h>
struct MyArray {
    ArrayElementType* data;
    //数组容量
    int capacity;
    //元素个数
    int length;
};
Queue cstl_queue_initQueue(int capacity) {
    return cstl_array_initArray(capacity);
}
int cstl_queue_getLength(Queue queue) {
    return cstl_array_getLength(queue);
}
bool cstl_queue_isEmpty(Queue queue) {
    return cstl_array_isEmpty(queue);
}
int cstl_queue_capacity(Queue queue) {
    return cstl_array_getCapacity(queue);
}
void cstl_queue_print(Queue queue) {
    printf("\n");
    for (int i = 0; i < queue.length; ++i) {
        printf("%d ", queue.data[i]);
    }
    printf("\n");
}
void cstl_queue_enqueue(Queue* queue, QueueElementType element) {
    cstl_array_addLast(queue, element);
}
QueueElementType cstl_queue_dequeue(Queue* queue) {
    return cstl_array_removeFirst(queue);
}

int main() {
    Queue queue = cstl_queue_initQueue(10);
    for (int i = 0; i < 15; ++i) {
        cstl_queue_enqueue(&queue, i);
        cstl_queue_print(queue);
        if (i % 3 == 0) {
            cstl_queue_dequeue(&queue);
            cstl_queue_print(queue);
        }
    }
    for (int i = 0; i < 15; i++) {
        cstl_queue_dequeue(&queue);
        cstl_queue_print(queue);
    }
}
