//
// Created by bgst on 2020/9/17.
//

#ifndef DATASTRUCTWITHC_BST_H
#define DATASTRUCTWITHC_BST_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * 二分搜索树的元素类型
 */
typedef int TreeElementType;
/**
 * 指向二分搜索树节点的指针
 */
typedef struct BinaryTreeNode *BSTNodeP;
/**
 * 二分搜索树节点的别名
 */
typedef struct BinaryTreeNode BSTNode;
/**
 * 指向二分搜索树的指针
 */
typedef struct BinarySearchTree *BSTP;
/**
 * 二分搜索树的别名
 */
typedef struct BinarySearchTree BST;

/**
 * 二分搜索树的节点结构
 */
struct BinaryTreeNode {
    TreeElementType element;
    BSTNodeP left;
    BSTNodeP right;
};
/**
 * 二分搜索树的结构
 */
struct BinarySearchTree {
    int size;
    BSTNodeP root;
};

/**
 * 构造空二分搜索树
 * @return 二分搜索树pointer
 */
BSTP cstl_tree_InitBST();
/**
 * 随机创建一颗二分搜索树
 * @param bst 空的二分搜索树
 */
void cstl_tree_createBSTD(BSTP bst);
/**
 * 二分搜索树的大小
 * @param bst 二分搜索树
 * @return 大小
 */
int cstl_tree_BSTSize(BSTP bst);
/**
 * 判断二分搜索树是否为空
 * @param bst 二分搜索树
 * @return true 空
 */
bool cstl_tree_isEmpty(BSTP bst);
/**
 * 向二分搜索树忠添加元素
 * @param bst 二分搜索树
 * @param element  元素
 */
void cstl_tree_add(BSTP bst, TreeElementType element);
/**
 * 在二分搜索树中的某个节点添加元素
 * @param bst 二分搜索树
 * @param node 二分搜索树中的节点
 * @param element 元素
 * @return
 */
static BSTNodeP cstl_tree_addElement(BSTP bst, BSTNodeP node, TreeElementType element);
/**
 * 创建一个新的节点并赋值
 * @param element 元素
 * @return 创建完的节点的指针
 */
static BSTNodeP cstl_tree_createNode(TreeElementType element);
/**
 * 二分搜索树中是否包含元素element
 * @param bst 二分搜索树
 * @param element 元素
 * @return 包含 true
 */
bool cstl_tree_contains(BSTP bst, TreeElementType element);
/**
 * 在二分搜索树中以node为根的子树中是否存在元素element
 * @param bst 二分搜索树
 * @param node 节点
 * @param element 元素
 * @return 包含 true
 */
static bool cstl_tree_containsElement(BSTP bst, BSTNodeP node, TreeElementType element);
/**
 * 前序遍历二分搜索树（递归）
 * @param bst 二分搜索树
 */
void cstl_tree_preOrder(BSTP bst);
static void cstl_tree_preOrderTraversal(BSTP bst, BSTNodeP node);
/**
 * 前序遍历二分搜索树（非递归）
 * @param bst
 */
void cstl_tree_preOrder_noRec(BSTP bst);
/**
 * 中序遍历二分搜索树（递归）
 * @param bst 二分搜索树
 */
void cstl_tree_inOrder(BSTP bst);
static void cstl_tree_inOrderTraversal(BSTP bst, BSTNodeP node);
/**
 * 中序遍历二分搜索树（非递归）
 * @param bst 二分搜索树
 */
void cstl_tree_inOrder_noRec(BSTP bst);
/**
 * 后续遍历二分搜索树（递归）
 * @param bst 二分搜索树
 */
void cstl_tree_postOrder(BSTP bst);
static void cstl_tree_postOrderTraversal(BSTP bst, BSTNodeP node);

#endif//DATASTRUCTWITHC_BST_H
