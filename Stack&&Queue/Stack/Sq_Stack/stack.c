//
// Created by bgst on 2020/9/7.
//

#include "stack.h"

#include <memory.h>
#include <stdlib.h>


Stack init(int size) {
    Stack stack;
    stack.data = (StackElement*) malloc(sizeof(StackElement) * size);
    memset(stack.data, 0, sizeof(StackElement) * size);
    stack.size = size;
    stack.top = -1;
    return stack;
}
bool destroy(Stack* stack) {
    free(stack->data);
    stack->top = -1;
    stack->size = 0;
    return true;
}
bool isEmpty(Stack* stack) {
    return stack->top == -1 ? true : false;
}
bool isFull(Stack* stack) {
    return stack->top >= stack->size ? true : false;
}
bool push(Stack* stack, StackElement element) {
    if (isFull(stack))
        return false;
    stack->data[++stack->top] = element;
    return true;
}
bool pop(Stack* stack) {
    if (isEmpty(stack))
        return false;
    stack->top--;
    return true;
}
StackElement top(Stack* stack) {
    if (isEmpty(stack))
        return false;
    return stack->data[stack->top];
}
bool symmetryWithStack(LinkList L, Stack* stack) {
    LNode *slow, *fast, *cur;
    StackElement element;
    slow = fast = L->next;

    while (fast != NULL && fast->next != NULL) {
        //        printf("\n slow: %d ", slow->data);
        //        printf(" fast: %d \n", fast->data);
        push(stack, slow->data);
        cur = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    //    printf("\n slow: %d \n", slow->data);
    //    printf("\n slow->next: %d \n", slow->next->data);
    //    ListTraverse_L(&L);
    //    ListTraverse_L(&cur);
    if (fast) {//odd
        slow = slow->next;
    }
    while (slow) {
        element = top(stack);
        pop(stack);
        if (slow->data != element)
            break;
        slow = slow->next;
    }

    if (isEmpty(stack)) {
        printf("\n symmetry\n");
        return true;
    } else {
        printf("\n not symmetry\n");
        return false;
    }
}
void traverseStack(Stack* stack) {
    while (!isEmpty(stack)) {
        printf(" %d", top(stack));
        pop(stack);
    }
}
