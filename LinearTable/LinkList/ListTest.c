//
// Created by 14991 on 2020/8/22.
//

#include "ListTest.h"
#include "LinkList.h"
#include "../SLinkList/SLinkList.h"
#include "../SqList/SqList.h"


int main() {
    printf("\n ==========================   H e l l o , W o r l d ! =================================== \n");

    test_SqList();

    test_LinkList();

    test_SLinkList();
    return 0;
}


void test_SqList() {
    printf("\n /************** test_SqList ***************/ \n");

    SqListDynamic Sq;
    if (InitList_Sq(&Sq))
        printf("\nInitial Successful\n");
    else
        printf("\nInitial Fail\n");

    for (int i = 0; i < 20; ++i) {
        ListInsert_Sq(&Sq, i + 1, i);
    }

    printf("\nList Length is %d\n", ListLength_Sq(Sq));
    ElemType elemType, pre_e, next_e, del_e;
    int index;
    GetElem_Sq(Sq, 5, &elemType);
    PriorElem_Sq(Sq, 4, &pre_e);
    NextElem_Sq(Sq, 4, &next_e);
    LocateElem_Sq(Sq, 4, &index);
    printf("\n第%d个元素是%d\n", 5, elemType);
    printf("\n第%d个元素前驱%d\n", 5, pre_e);
    printf("\n第%d个元素后继%d\n", 5, next_e);
    printf("\n%d是第 %d 个元素\n", 4, next_e);
    ListTraverse_Sq(Sq);
    ListDelete_Sq(&Sq, 5, &del_e);
    printf("\n第%d个元素是%d\n", 5, elemType);
    ListTraverse_Sq(Sq);

    ClearList_Sq(&Sq);
    DestroyList_Sq(&Sq);
    ListTraverse_Sq(Sq);
}

void test_LinkList() {
    printf("\n /************** test_LinkList ***************/ \n");


    printf("\n == after createListTail  \n");
    LinkList L1;
    createListTail(&L1, 19);
    ListTraverse_L(&L1);


    printf("\n == after ListInsert_L   \n");
    ElemType elemType1 = 5;
    ListInsert_L(L1, 5, elemType1);
    ListTraverse_L(&L1);

    printf("\n == after ListDelete_L   \n");
    ListDelete_L(L1, 5, &elemType1);
    printf("\n del elem %d \n", elemType1);
    ListTraverse_L(&L1);

}

void test_SLinkList() {

    printf("\n /************** test_SLinkList ***************/ \n");

    SLinkList SL;
    InitList_SL(SL);

    srand(time(NULL));
    for (int i = 0; i < 5; ++i) {
        ListInsert_SL(SL, i + 1, rand() % 100 + 1);
    }

    printf("\n == after InitList_SL&&ListInsert_SL \n");
    ListTraverse_SL(SL);


    ListDel_SL(SL, 3);
    printf("\n == after ListDel_SL \n");

    ListTraverse_SL(SL);
}