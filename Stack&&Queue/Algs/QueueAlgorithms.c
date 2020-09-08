//
// Created by bgst on 2020/9/8.
//

#include "QueueAlgorithms.h"
void reverse_queue(TQ* queue, Stack* stack) {
    int element;
    while (!isEmptyTQueue(queue)) {
        element = deQueueTQueue(queue);
        //        printf(" %d ", element);
        push(stack, element);
    }
    printf("\n");
    while (!isEmpty(stack)) {
        element = top(stack);
        enQueueTQueue(queue, element);
        pop(stack);
        //        printf(" %d ", element);
    }
    //    traverseTQueue(queue);
}

int main() {
    int size = 5;
    int element;
    TQ* queue = initTQ(size);
    Stack stack = init(size);

    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        element = rand() % 100 + 1;
        enQueueTQueue(queue, element);
    }

    reverse_queue(queue, &stack);
}