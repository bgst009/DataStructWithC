//
// Created by bgst on 2020/9/1.
//
#include "LinkList.h"

int main() {
    printf("\n == after createListTail  \n");
    LinkList L1;
    createListTail(&L1, 19);
    ListTraverse_L(&L1);
    printf("\n");
    L1 = ReverseList_L(L1);
    ListTraverse_L(&L1);
    printf("\n");
    L1 = ReverseList_L_2(L1);
    ListTraverse_L(&L1);

    return 0;
}
