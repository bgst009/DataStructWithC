//
// Created by bgst on 2020/9/17.
//

#include "BST.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

BSTP cstl_tree_InitBST() {
    BSTP bst = (BSTP) malloc(sizeof(BST));
    bst->root = NULL;
    bst->size = 0;
    return bst;
}
void cstl_tree_createBSTD(BSTP bst) {
    srand(time(NULL));
    TreeElementType element = 10;
    for (int i = 0; i < 10; ++i) {
        element = rand() % 100 + 1;
        cstl_tree_add(bst, element);
        //        printf("add %dth element : %d . tree size %d\n", i, element, bst->size);
        //        cstl_tree_preOrder(bst);
        //        printf("\n");
    }
}
int cstl_tree_BSTSize(BSTP bst) {
    return bst->size;
}
bool cstl_tree_isEmpty(BSTP bst) {
    return bst->size == 0 ? true : false;
}
void cstl_tree_add(BST* bst, TreeElementType element) {
    bst->root = cstl_tree_addElement(bst, bst->root, element);
}
BSTNodeP cstl_tree_addElement(BST* bst, BSTNodeP node, TreeElementType element) {
    if (node == NULL) {
        bst->size++;
        return cstl_tree_createNode(element);
    }
    if (element < node->element) {
        node->left = cstl_tree_addElement(bst, node->left, element);
    } else if (element > node->element) {
        node->right = cstl_tree_addElement(bst, node->right, element);
    }
    return node;
}
BSTNodeP cstl_tree_createNode(TreeElementType element) {
    BSTNodeP node = (BSTNodeP) malloc(sizeof(BSTNode));
    node->left = node->right = NULL;
    node->element = element;
    return node;
}
bool cstl_tree_contains(BSTP bst, TreeElementType element) {
    return cstl_tree_containsElement(bst, bst->root, element);
}
bool cstl_tree_containsElement(BSTP bst, BSTNodeP node, TreeElementType element) {
    if (node == NULL) {
        return false;
    }
    if (node->element == element) {
        return true;
    } else if (element < node->element) {
        return cstl_tree_containsElement(bst, node->left, element);
    } else {
        return cstl_tree_containsElement(bst, node->right, element);
    }
}
void cstl_tree_preOrder(BSTP bst) {
    printf("\n pre order\n");
    cstl_tree_preOrderTraversal(bst, bst->root);
    printf("\n");
}
void cstl_tree_preOrderTraversal(BSTP bst, BSTNodeP node) {
    if (node == NULL)
        return;

    printf("%d ", node->element);
    cstl_tree_preOrderTraversal(bst, node->left);
    cstl_tree_preOrderTraversal(bst, node->right);
}
void cstl_tree_inOrder(BSTP bst) {
    printf("\n in order\n");
    cstl_tree_inOrderTraversal(bst, bst->root);
    printf("\n");
}
void cstl_tree_inOrderTraversal(BSTP bst, BSTNodeP node) {
    if (node == NULL)
        return;

    cstl_tree_inOrderTraversal(bst, node->left);
    printf("%d ", node->element);
    cstl_tree_inOrderTraversal(bst, node->right);
}
void cstl_tree_postOrder(BSTP bst) {
    printf("\n post order\n");
    cstl_tree_postOrderTraversal(bst, bst->root);
    printf("\n");
}
void cstl_tree_postOrderTraversal(BSTP bst, BSTNodeP node) {
    if (node == NULL)
        return;

    cstl_tree_postOrderTraversal(bst, node->left);
    cstl_tree_postOrderTraversal(bst, node->right);
    printf("%d ", node->element);
}

int main() {
    BSTP bst = cstl_tree_InitBST();
    cstl_tree_createBSTD(bst);
    cstl_tree_preOrder(bst);
    cstl_tree_inOrder(bst);
    cstl_tree_postOrder(bst);
}
