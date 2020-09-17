//
// Created by bgst on 2020/9/11.
//

#ifndef ARRAY_CIRCULARQUEUE_H
#define ARRAY_CIRCULARQUEUE_H

#include <stdbool.h>
#include <stdlib.h>
typedef struct {
    int* data;
    int capacity;
    int size;
    int front;
    int rear;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    queue->data = (int*) malloc(sizeof(int) * k);
    queue->capacity = k;
    queue->size = 0;
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if ((obj->rear + 1) % obj->capacity == obj->front) {
        return false;
    }
    obj->data[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->size++;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->front == obj->rear)
        return false;//empty queue
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->front == obj->rear)
        return false;//empty queue
    return obj->data[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->front == obj->rear)
        return false;//empty queue
    return obj->data[obj->rear];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear ? true : false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % obj->capacity == obj->front ? true : false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}
#endif//ARRAY_CIRCULARQUEUE_H
