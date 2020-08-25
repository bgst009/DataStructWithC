//
// Created by bgst on 2020/8/25.
//

#include "./LinkQueue/LinkQueue.h"

void testLQ();

int main() {


    testLQ();

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



