//
// Created by bgst on 2020/8/28.
//

#include "BinarySearchTree.h"
#include "./LinkQueue/LinkQueue.h"

struct TreeNode {
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T) {
    if (T == NULL)
        return NULL;
    if (X < T->Element)
        return Find(X, T->Left);
    else if (X > T->Element)
        return Find(X, T->Right);
    else
        return T;
}

Position FindMin(SearchTree T) {
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

Position FindMax(SearchTree T) {
    if (T != NULL) {
        while (T->Right != NULL)
            T = T->Right;
    }
    return T;
}

SearchTree Insert(ElementType X, SearchTree T) {
    if (T == NULL) {
        T = (SearchTree) malloc(sizeof(struct TreeNode));
        if (T == NULL) {
            printf("\n Out of space!!! \n");
            return T;
        } else {
            T->Right = T->Left = NULL;
            T->Element = X;
        }
    } else if (X < T->Element)
        T->Left = Insert(X, T->Left);
    else if (X > T->Element)
        T->Right = Insert(X, T->Right);

    return T;
}

SearchTree Delete(ElementType X, SearchTree T) {
    Position TmpCell;
    if (T == NULL) {
        printf("\n Element not found \n");
        return NULL;
    } else if (X < T->Element)
        T->Left = Delete(X, T->Left);
    else if (X > T->Element)
        T->Right = Delete(X, T->Right);
    else if (T->Left && T->Right) {
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Element, T->Right);
    } else {
        TmpCell = T;
        if (T->Left == NULL)
            T = T->Right;
        else if (T->Right == NULL)
            T = T->Left;
        free(TmpCell);
    }

    return T;
}

ElementType Retrieve(Position P) {
    if (P == NULL)
        return -1;
    return P->Element;
}

void InOrder(SearchTree T) {
    if (T == NULL)
        return;

    InOrder(T->Left);
    printf(" %d ", Retrieve(T));
    InOrder(T->Right);
}



