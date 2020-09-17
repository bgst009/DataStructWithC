//
// Created by bgst on 2020/9/17.
//

#include "BST.h"

#include "../Stack/c_stack.h"
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
static int int_comparer(value_type x, value_type y) {
    return *(int*) x - *(int*) y;
}
void cstl_tree_preOrder_noRec(BSTP bst) {
    c_stack stack;
    __c_stack(&stack, int_comparer);
    BSTNodeP p = bst->root;
    while (p || !c_stack_empty(&stack)) {
        if (p) {

            int elem = p->element;
            printf("%d ", elem);

            c_stack_push(&stack, p);
            p = p->left;
        } else {
            p = c_stack_top(&stack);
            c_stack_pop(&stack);
            p = p->right;
        }
    }
    printf("\n");
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
void cstl_tree_inOrder_noRec(BSTP bst) {
    c_stack stack;
    __c_stack(&stack, int_comparer);
    BSTNodeP p = bst->root;
    while (p || !c_stack_empty(&stack)) {
        if (p) {
            c_stack_push(&stack, p);
            p = p->left;
        } else {
            p = c_stack_top(&stack);
            int elem = p->element;
            printf("%d ", elem);
            c_stack_pop(&stack);
            p = p->right;
        }
    }
    printf("\n");
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
    //    c_stack stack;
    //    int ary[] = {2, 3, 4, 5, 6, 7, 8, 9, 0, 1};
    //    __c_stack(&stack, int_comparer);
    //
    //    for (int i = 0; i < 5; ++i) {
    //        c_stack_push(&stack, &ary[i]);
    //    }
    //    for (int i = 0; i < 5; ++i) {
    //        void* element = c_stack_top(&stack);
    //        int* elem = element;
    //        c_stack_pop(&stack);
    //        printf(" %d ", *elem);
    //    }
    BSTP bst = cstl_tree_InitBST();
    cstl_tree_createBSTD(bst);
    cstl_tree_inOrder(bst);
    cstl_tree_inOrder_noRec(bst);
    cstl_tree_preOrder(bst);
    cstl_tree_preOrder_noRec(bst);
}