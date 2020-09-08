//
// Created by bgst on 2020/8/24.
//

#include "LinkStack_test.h"


void test_LinkStack() {
    LinkStack linkStack;
    InitStack_LS(&linkStack);

    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        SElemType elem = rand() % 100 + 1;
        Push_LS(&linkStack, elem);
    }

    SElemType elem;
    Top_LS(&linkStack, &elem);
    printf(" Get top elem %d", elem);

    printf("\n Stack length %d \n", StackLength_LS(&linkStack));
    print_LS(&linkStack);
    printf("\n Stack length %d \n", StackLength_LS(&linkStack));

    ClearStack_LS(&linkStack);
    for (int i = 0; i < 10; ++i) {
        SElemType elem = rand() % 100 + 1;
        Push_LS(&linkStack, elem);
    }
    print_LS(&linkStack);
    DestroyStack_LS(&linkStack);
    print_LS(&linkStack);

}

void conversion() {
    LinkStack LS;
    InitStack_LS(&LS);

    int N;
    scanf("%d", &N);
    while (N) {
        Push_LS(&LS, N % 8);
        N /= 8;
    }
    while (!StackEmpty_LS(&LS)) {
        print_LS(&LS);
    }

}

