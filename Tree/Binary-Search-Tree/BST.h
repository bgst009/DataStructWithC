//
// Created by bgst on 2020/9/17.
//

#ifndef DATASTRUCTWITHC_BST_H
#define DATASTRUCTWITHC_BST_H
#define true 1
#define false 0

typedef int bool;
typedef int TreeElementType;
typedef struct BinaryTreeNode *BSTNodeP;
typedef struct BinaryTreeNode BSTNode;
typedef struct BinarySearchTree *BSTP;
typedef struct BinarySearchTree BST;

struct BinaryTreeNode {
    TreeElementType element;
    BSTNodeP left;
    BSTNodeP right;
};
struct BinarySearchTree {
    int size;
    BSTNodeP root;
};

/**
 * 构造空二分搜索树
 * @return 二分搜索树pointer
 */
BSTP cstl_tree_InitBST();
void cstl_tree_createBSTD(BSTP bst);
int cstl_tree_BSTSize(BSTP bst);
bool cstl_tree_isEmpty(BSTP bst);
void cstl_tree_add(BSTP bst, TreeElementType element);
static BSTNodeP cstl_tree_addElement(BSTP bst, BSTNodeP node, TreeElementType element);
static BSTNodeP cstl_tree_createNode(TreeElementType element);
bool cstl_tree_contains(BSTP bst, TreeElementType element);
static bool cstl_tree_containsElement(BSTP bst, BSTNodeP node, TreeElementType element);
void cstl_tree_preOrder(BSTP bst);
static void cstl_tree_preOrderTraversal(BSTP bst, BSTNodeP node);
void cstl_tree_inOrder(BSTP bst);
static void cstl_tree_inOrderTraversal(BSTP bst, BSTNodeP node);
void cstl_tree_postOrder(BSTP bst);
static void cstl_tree_postOrderTraversal(BSTP bst, BSTNodeP node);

#endif//DATASTRUCTWITHC_BST_H
