//
// Created by bgst on 2020/9/1.
//
#include "LinkList.h"

int main() {
    printf("\n == after createListTail  \n");
    LinkList L1;
    createIncreaseListHead(&L1, 10);
    ListTraverse_L(&L1);
    printf("\n");

    DeleteRepeatElement(L1);
    ListTraverse_L(&L1);
    printf("\n");

    //    LinkList AB[2];
    //    DepartList(L1, AB);
    //    printf("\n A : ");
    //    ListTraverse_L(&AB[0]);
    //    printf("\n B : ");
    //    ListTraverse_L(&AB[1]);


    //    ReversePrint_Recursive(L1);
    //    printf("\n");
    //    ReversePrint_Stack(L1);
    //    L1 = ReverseList_L(L1);
    //    ListTraverse_L(&L1);

    return 0;
}
