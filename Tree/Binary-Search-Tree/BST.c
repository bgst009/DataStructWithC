//
// Created by bgst on 2020/9/17.
//

#include "BST.h"

#include "../include/c_queue.h"
#include "../include/c_stack.h"
#include "../include/c_vector.h"
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
void cstl_tree_levelOrder(BSTP bst) {
    if (bst->root == NULL)
        return;

    c_queue queue;
    __c_queue(&queue, int_comparer);

    c_queue_push(&queue, bst->root);

    while (!c_queue_empty(&queue)) {

        BSTNode* temp = c_queue_front(&queue);
        printf("%d ", temp->element);

        c_queue_pop(&queue);

        if (temp->left != NULL) {
            c_queue_push(&queue, temp->left);
        }
        if (temp->right != NULL) {
            c_queue_push(&queue, temp->right);
        }
    }
    printf("\n");
}

//static int ary[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//#define SIZE 10
//
//
//static int int_comparer(value_type x, value_type y)
//{
//    return *(int *)x - *(int *)y;
//}
//
//static int create_with_push(c_pqueue ps, int ary[]) {
//    int i = 0;
//    for (i = 0; i < SIZE; ++i) {
//        c_queue_push(ps, &ary[i]);
//    }
//    return 0;
//}
//
//static int print_queue(c_pqueue ps) {
//    c_vector tmpvt;
//    __c_vector(&tmpvt, int_comparer);
//
//    printf("queue is : \n");
//    while (!c_queue_empty(ps)) {
//        int* tmp = c_queue_front(ps);
//        printf("front is : %d, size is : %d, back is : %d\n",
//               *tmp,
//               c_queue_size(ps),
//               *(int*) c_queue_back(ps));
//        c_queue_pop(ps);
//        c_vector_push_back(&tmpvt, tmp);
//    }
//
//    // recover queue
//    do {
//        c_iterator iter = c_vector_begin(&tmpvt);
//        c_iterator end = c_vector_end(&tmpvt);
//        for (; !ITER_EQUAL(iter, end); ITER_INC(iter)) {
//            c_queue_push(ps, ITER_REF(iter));
//        }
//    } while (0);
//
//    __c_rotcev(&tmpvt);
//    return 0;
//}
//
//static int clear_queue(c_pqueue ps) {
//    while (!c_queue_empty(ps)) {
//        c_queue_pop(ps);
//    }
//
//    return 0;
//}
//
//
//int t_queue() {
//    c_queue queue, queue1;
//    int ary1[] = {2, 3, 4, 5, 6, 7, 8, 9, 0, 1};
//    __c_queue(&queue, int_comparer);
//    __c_queue(&queue1, int_comparer);
//
//    create_with_push(&queue, ary);
//    printf("queue: \n");
//    print_queue(&queue);
//
//    create_with_push(&queue1, ary1);
//    printf("queue1: \n");
//    print_queue(&queue1);
//
//    if (c_queue_equal(&queue, &queue1))
//        printf("queue == queue1\n");
//    else
//        printf("queue != queue1\n");
//
//    clear_queue(&queue);
//    clear_queue(&queue1);
//
//    create_with_push(&queue, ary1);
//    printf("queue: \n");
//    print_queue(&queue);
//
//    create_with_push(&queue1, ary1);
//    printf("queue1: \n");
//    print_queue(&queue1);
//
//    if (c_queue_equal(&queue, &queue1))
//        printf("queue == queue1\n");
//    else
//        printf("queue != queue1\n");
//
//
//    clear_queue(&queue);
//    clear_queue(&queue1);
//
//    create_with_push(&queue, ary);
//    printf("queue: \n");
//    print_queue(&queue);
//
//    create_with_push(&queue1, ary1);
//    printf("queue1: \n");
//    print_queue(&queue1);
//
//    if (c_queue_less(&queue, &queue1))
//        printf("queue < queue1\n");
//    else
//        printf("queue >= queue1\n");
//
//    clear_queue(&queue);
//    clear_queue(&queue1);
//
//    create_with_push(&queue, ary1);
//    printf("queue: \n");
//    print_queue(&queue);
//
//    create_with_push(&queue1, ary1);
//    printf("queue1: \n");
//    print_queue(&queue1);
//
//    if (c_queue_less(&queue, &queue1))
//        printf("queue < queue1\n");
//    else
//        printf("queue >= queue1\n");
//
//
//    __c_eueuq(&queue);
//    __c_eueuq(&queue1);
//
//    printf("\nfinish testing queue!\n\n");
//
//    return 0;
//}

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
    //    cstl_tree_inOrder(bst);
    //    cstl_tree_inOrder_noRec(bst);
    //    cstl_tree_preOrder(bst);
    //    cstl_tree_preOrder_noRec(bst);
    //    t_queue();
    cstl_tree_levelOrder(bst);
}