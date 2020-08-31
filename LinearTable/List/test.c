//
// Created by bgst on 2020/8/31.
//

#include "list.h"

int main() {

    List list, list2;
    list = InitList();
    list2 = InitList();
    srand(time(NULL));
    ElementType elem;
    int length = 10;
    createList_Head(list, length);
    createList_Tail(list2, length);
    Insert(5, list);
    Insert(5, list2);
    ListTraverse(list);
    ListTraverse(list2);
    printf("\n%d\n", Retrieve(FindPrev(9, list)));
    printf("\n%d\n", Retrieve(FindPrev(9, list2)));


    return 0;
}
