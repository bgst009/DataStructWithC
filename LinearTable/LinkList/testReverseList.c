//
// Created by bgst on 2020/9/1.
//
#include "LinkList.h"

int main() {
    printf("\n == after createListTail  \n");
    LinkList L1;
    createListTail(&L1, 5);
    ListTraverse_L(&L1);
    printf("\n");
    ReversePrint_Recursive(L1);
    printf("\n");
    ReversePrint_Stack(L1);
    L1 = ReverseList_L(L1);
    ListTraverse_L(&L1);

    return 0;
}
