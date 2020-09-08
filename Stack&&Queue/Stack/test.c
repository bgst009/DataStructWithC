//
// Created by 14991 on 2020/8/25.
//

#include "list/LinkList.h"
#include "stack.h"
void test01();
void test02();
int main() {
    test02();
    return 0;
}
void test02() {
    LinkList list = (LinkList) malloc(sizeof(LNode));
    int size = 12;
    createSymmetricLinkList(list, size);
    ListTraverse_L(&list);

    Stack stack = init(22);
    //    for(int i = 0; i < size; i++){
    //        push(&stack, i);
    //    }
    //    traverseStack(&stack);
//    ListTraverse_L(&list);

    symmetryWithStack(list, &stack);
}

void test01() {
    //    printf("\n Link Stack \n");
    //    test_LinkStack();
    //    printf("\n Sq_stack\n");
    //    test_Sq_Stack();
    //
    //    conversion();
}
