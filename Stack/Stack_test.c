//
// Created by 14991 on 2020/8/22.
//

#include "Stack_test.h"

int main() {
    printf("Hello World\n");
    test_Sq_Stack();
    return 0;
}

void test_Sq_Stack() {


    SqStack SS;
    InitStack_Sq(&SS);


    srand(time(NULL));
    for (int i = 0; i < 30; ++i) {
        SElemType elem;
        elem = rand() % 100 + 1;
        printf(" %d ", elem);
        Push_Sq(&SS, elem);
        //每 3 次入栈，弹 1 此栈
        if (i % 3 == 0) {
            Pop_Sq(&SS, &elem);
        }
    }


    printf("\n\n");
    printf("\nStackLength = %d\n", StackLength_Sq(&SS));
    for (; !StackEmpty_Sq(&SS);) {
        SElemType elem;
        GetTop_Sq(&SS, &elem);
        printf("\t%d\t", elem);
        Pop_Sq(&SS, &elem);
    }

    printf("\nStackLength = %d\n", StackLength_Sq(&SS));

    ClearStack_Sq(&SS);
    for (int i = 0; i < 30; ++i) {
        SElemType elem;
        elem = rand() % 100 + 1;
        printf(" %d ", elem);
        Push_Sq(&SS, elem);
        //每 3 次入栈，弹 1 此栈
        if (i % 3 == 0) {
            Pop_Sq(&SS, &elem);
        }
    }

    DestroyStack_Sq(&SS);
    printf("\nStackLength = %d\n", StackLength_Sq(&SS));


}