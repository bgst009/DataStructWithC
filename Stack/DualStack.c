//
// Created by bgst on 2020/9/7.
//

#include "DualStack.h"

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
DStack initD(int size) {
    DStack stack;
    stack.data = (StackElement *) malloc(sizeof(StackElement) * size);
    memset(stack.data, 0, sizeof(StackElement) * size);
    stack.top[0] = -1;
    stack.top[1] = size;
    stack.size = size;
    return stack;
}
bool pushD(DStack *stack, StackElement element, int i) {
    if (stack->top[0] + 1 == stack->top[1]) {//stack full
        return false;
    }
    if (i == 0) {
        stack->data[++stack->top[0]] = element;
        return true;
    }
    if (i == 1) {
        stack->data[--stack->top[1]] = element;
        return true;
    } else
        return false;
}
bool popD(DStack *stack, int i) {
    switch (i) {
        case 0:
            if (stack->top[0] == -1) return false;
            stack->top[0]--;
            break;
        case 1:
            if (stack->top[1] == stack->size) return false;
            stack->top[1]++;
            break;
        default:
            return false;
    }
    return true;
}
StackElement topD(DStack *stack, int i) {
    switch (i) {
        case 0:
            if (stack->top[0] == -1) return -1;
            return stack->data[stack->top[0]];
        case 1:
            if (stack->top[1] == stack->size) return -1;
            return stack->data[stack->top[1]];
            break;
        default:
            return -1;
    }
}
void traverseStackD(DStack stack) {
    for (int i = 0; i < stack.size; ++i) {
        printf(" %d ", stack.data[i]);
    }
    printf("\n");
}


int main() {

    int size = 10;
    DStack stack = initD(size);
    //    traverseStackD(stack);
    for (int i = 0; i < 5; ++i) {
        pushD(&stack, i, 0);
    }
    for (int i = 0; i < size - 5; ++i) {
        pushD(&stack, i++, 1);
    }
    traverseStackD(stack);
    printf("\n%d", topD(&stack, 1));
    printf("\n%d", topD(&stack, 0));
}