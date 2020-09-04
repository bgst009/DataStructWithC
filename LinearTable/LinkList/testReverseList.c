//
// Created by bgst on 2020/9/1.
//
#include "LinkList.h"

void test01();
void test02();
void test03();

int main() {
    test03();
    return 0;
}

void test03() {
    LinkList list1, list2, list3;
    int size = 10;
    createListHead(&list1, size + 1);
    createListHead(&list2, size - 1);
    createListHead(&list3, size / 2);
    //    ListTraverse_L(&list1);
    //    ListTraverse_L(&list2);
    ListTraverse_L(&list3);

    connectLindList(list1, list3);
    connectLindList(list2, list3);
    ListTraverse_L(&list1);
    ListTraverse_L(&list2);

    LNode* node;
    LinkList L;
    node = findCoNode(list1, list2);
    L->next=node;
    ListTraverse_L(&L);
}

void test02() {

    DLinkList L1 = (DLinkList) malloc(sizeof(LNode));
    createDoubleList(L1, 15);
    ListTraverse_DL(L1);

    srand(time(NULL));
    for (int i = 0; i < 50; ++i) {
        int elem = rand() % 10 + 1;
        printf("find %d \n", elem);
        Locate(L1, elem);
    }

    //    Locate(L1,5);

    ListTraverse_DL(L1);


    //    DLinkList DL1,DL2;
    //    createDoubleList(DL1, 5);
    //    ListTraverse_DL(DL1);
    //    createDoubleList(DL2, 8);
    //    ListTraverse_DL(DL2);
    //    connectDLinkList(DL1,DL2);
    //    ListTraverse_DL(DL1);

    //    if (symmetry(DL))
    //        printf("\n Symmetry test true \n");
    //    else
    //        printf("\n Symmetry test false \n");
}

void test01() {
    printf("\n == after createListTail  \n");
    LinkList L1, L2;
    createIncreaseListHead(&L1, 20);
    createIncreaseListHead(&L2, 20);
    //    ListTraverse_L(&L1);
    //    printf("\n");
    //    ListTraverse_L(&L2);
    //    printf("\n");

    L1 = ReverseList_L(L1);
    L2 = ReverseList_L(L2);

    ListTraverse_L(&L1);
    printf("\n");
    ListTraverse_L(&L2);
    printf("\n");

    //    MergeList(L1, L2);

    UnionLinkList(L1, L2);
    ListTraverse_L(&L1);
    printf("\n");

    //    DeleteRepeatElement(L1);
    //    ListTraverse_L(&L1);
    //    printf("\n");

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
}
