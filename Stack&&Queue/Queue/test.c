//
// Created by bgst on 2020/8/25.
//

#include "./LinkQueue/LinkQueue.h"
#include "./SqQueue/SqQueue.h"

void testLQ();

void testSQ();

int main() {


//    testLQ();
    testSQ();
    return 0;
}


void testLQ() {
    printf("\n test LQ\n");

    LinkQueue linkQueue;
    InitQueue_LQ(&linkQueue);
    srand(time(NULL));
    QElemType elem;

    for (int i = 0; i < 15; ++i) {
        elem = rand() % 100 + 1;
        EnQueue_LQ(&linkQueue, elem);
    }

    printf("\n Queue's length %d \n", QueueLength_LQ(&linkQueue));
    GetHead_LQ(&linkQueue, &elem);
    printf("\n Queue's head %d \n", elem);
    print_LQ(&linkQueue);

    for (int i = 0; i < 15; ++i) {
        elem = rand() % 100 + 1;
        EnQueue_LQ(&linkQueue, elem);
    }

    ClearQueue_LQ(&linkQueue);
    print_LQ(&linkQueue);

    DestroyQueue_LQ(&linkQueue);
    print_LQ(&linkQueue);

}

void testSQ() {
    SqQueue sqQueue;
    InitQueue_SQ(&sqQueue);

    srand(time(NULL));
    QElemType elem;

    for (int i = 0; i < 105; ++i) {
        elem = rand() % 100 + 1;
        EnQueue_SQ(&sqQueue, elem);
    }
    printf("\n Queue's length %d \n", QueueLength_SQ(&sqQueue));
    print_SQ(&sqQueue);
    printf("\n Queue's length %d \n", QueueLength_SQ(&sqQueue));

    for (int i = 0; i < 105; ++i) {
        elem = rand() % 100 + 1;
        EnQueue_SQ(&sqQueue, elem);
    }

    ClearQueue_SQ(&sqQueue);
    print_SQ(&sqQueue);

    DestroyQueue_SQ(&sqQueue);
    print_SQ(&sqQueue);

}


