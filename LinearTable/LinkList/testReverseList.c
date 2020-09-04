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

    LinkList list;
    int size = 10;
    createListHead(&list, size);
    ListTraverse_L(&list);
    list = ReverseList(list);
    ListTraverse_L(&list);


    //    LinkList list;
    //    int size = 50;
    //    createListHead(&list, size);
    //    ListTraverse_L(&list);
    //
    //    //构造环链表
    //    LNode *p1, *p2;
    //    ElemType elem = 1;
    //    p1 = findNode(list, elem);
    //    if (p1) printf("\n %d \n", p1->data);
    //    while (p1 == NULL && elem <= size) {
    //        p1 = findNode(list, elem);
    //    }
    //    p2 = findLastNode(list);
    //    p2->next = p1;
    //    //    ListTraverse_L(&list);
    //
    //    //测试
    //    p2 = findLoopStart(list);
    //    printf("\n loop start node val is %d \n", p2->data);
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
