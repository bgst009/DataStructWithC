//
// Created by bgst on 2020/9/8.
//

#include "QueueWithStack.h"
QS initQS(int size) {
    QS result;
    result.stack1 = init(size);
    result.stack2 = init(size);
    return result;
}
bool isEmptyQS(QS *queue) {
    return isEmpty(&queue->stack1) ? true : false;
}
bool isFullQS(QS *queue) {
    return isFull(&queue->stack1) ? true : false;
}
QSElement deQueueQS(QS *queue) {
    if (isEmptyQS(queue)) {
        printf("\n Queue is full !!!\n");
        return -1;
    }

    QSElement element;
    QSElement res;
    //把stack1 的元素全部压入stack2 中
    while (!isEmpty(&queue->stack1)) {
        element = top(&queue->stack1);
        pop(&queue->stack1);
        push(&queue->stack2, element);
    }

    res = top(&queue->stack2);
    pop(&queue->stack2);

    //把stack2 的元素全部压入stack1 中
    while (!isEmpty(&queue->stack2)) {
        element = top(&queue->stack2);
        pop(&queue->stack2);
        push(&queue->stack1, element);
    }
    return res;
}
bool enQueueQS(QS *queue, QSElement element) {
    if (isFullQS(queue)) {
        printf("\n Queue is full\n");
        return false;
    }

    push(&queue->stack1, element);
    return true;
}
void traverseQS(QS *queue) {
    printf("\n Traverse : ");
    QSElement element;
    while (!isEmptyQS(queue)) {
        element = deQueueQS(queue);
        printf("%d ", element);
    }
    printf("\n");
}

int main() {
    int size = 10;
    QSElement element;
    QS queue = initQS(size);
    srand(time(NULL));
    for (int i = 0; i < size + 2; ++i) {
        element = rand() % 100 + 1;
        enQueueQS(&queue, element);
    }
    //    traverseQS(&queue);
    for (int i = 0; i < size + 2; ++i) {
        element = deQueueQS(&queue);
        printf(" %d", element);
    }
}