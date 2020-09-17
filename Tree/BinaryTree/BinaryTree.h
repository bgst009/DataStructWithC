//
// Created by bgst on 2020/8/26.
//

#ifndef DATASTRUCTWITHC_BINARYTREE_H
#define DATASTRUCTWITHC_BINARYTREE_H

#include "./TreeNode.h"

/**
 * 构造空二叉树
 * @param biTree 二叉树指针
 * @return 成功构造空二叉树 true
 */
bool InitBiTree(BiTree *biTree);
/**
 * 初始条件：二叉树存在
 * @param biTree 二叉树指针
 * @return 成功销毁二叉树 true
 */
bool DestroyBiTree(BiTree *biTree);

/**
 * 先序构造二叉树，空格字符表示空树
 * @param biTree 二叉树指针
 * @return 成功构造二叉树 true
 */
bool CreateBiTree(BiTree *biTree);

/**
 * 初始条件：二叉树存在
 * @param biTree 二叉树指针
 * @return 清空二叉树 true 否则 false
 */
bool ClearBiTree(BiTree *biTree);

/**
 * 初始条件：二叉树存在
 * @param biTree 二叉树
 * @return 空树返回 true 否则返回 false
 */
bool BiTreeEmpty(BiTree biTree);

/**
 * 初始条件：二叉树存在
 * @param biTree 二叉树
 * @return 树的深度
 */
int BiTreeDepth(BiTree biTree);

/**
 * 初始条件：二叉树存在
 * @param biTree 二叉树
 * @return 返回根
 */
BiTNode *Root(BiTree biTree);

/**
 * 初始条件：二叉树存在
 * @param biTree 二叉树
 * @param elemNode 是 biTree 中的一个节点
 * @return elemNode 的值
 */
TElemType Value(BiTree biTree, BiTNode *elemNode);

/**
 * 初始条件：二叉树存在
 * @param biTree 二叉树
 * @param elemNode 是 biTree 中的一个节点
 * @param value 节点的值
 * @return 成功将 biTree 中的 elemNode 的值赋值为 value 则返回 true 否则 false
 */
bool Assign(BiTree biTree, BiTNode *elemNode, TElemType value);

/**
 * 初始条件：二叉树存在
 * @param biTree 二叉树
 * @param elemNode 是 biTree 中的一个节点
 * @return 若 elemNode 是非根节点则返回他的父节点，否则返回 空
 */
BiTNode *Parent(BiTree biTree, BiTNode *elemNode);

/**
 * 初始条件：二叉树存在
 * @param biTree 二叉树
 * @param elemNode 是 biTree 中的一个节点
 * @return 返回 elemNode 的的左孩子，若无返回 空
 */
BiTNode *LeftChild(BiTree biTree, BiTNode *elemNode);

/**
 * 初始条件：二叉树存在
 * @param biTree 二叉树
 * @param elemNode 是 biTree 中的一个节点
 * @return 返回 elemNode 的的右孩子，若无返回 空
 */
BiTNode *RightChild(BiTree biTree, BiTNode *elemNode);

/**
 * 初始条件：二叉树存在
 * @param biTree 二叉树
 * @param elemNode 是 biTree 中的一个节点
 * @return 返回 elemNode 的的左兄弟，若无或者 elemNode 为 biTree 的左孩子 返回 空
 */
BiTNode *LeftSibling(BiTree biTree, BiTNode *elemNode);

/**
 * 初始条件：二叉树存在
 * @param biTree 二叉树
 * @param elemNode 是 biTree 中的一个节点
 * @return 返回 elemNode 的的右兄弟，若无或者 elemNode 为 biTree 的右孩子 返回 空
 */
BiTNode *RightSibling(BiTree biTree, BiTNode *elemNode);

/**
 * 初始条件：二叉树存在
 *
 * @param biTree 二叉树
 * @param p biTree 中的某个节点
 * @param LR 0（左） 或 1（右）
 * @param c 非空二叉树不与 biTree 相交且右子树为空
 * @return 成功根据 LR，将 C 插入到 biTree 中 p 所指的节点的左或右孩子， p 原有的左或右子树成为 c 的左或者右子树 则返回true
 */
bool InsertChild(BiTree biTree, BiTNode *p, int LR, BiTNode *c);

/**
 * 初始条件：二叉树存在
 *
 * @param biTree 二叉树
 * @param p 中的某个节点
 * @param LR 0（左） 或 1（右）
 * @return 成功根据 LR 0（左） 或 1（右）删除 biTree 中 p 所指节点的左或者右子树 则返回true
 */
bool DeleteChild(BiTree biTree, BiTNode *p, int LR);

/**
 * 初始条件 elemNode 存在
 * 对节点的操作函数
 * @param elemNode 操作节点
 * @return
 */
bool Visit(BiTNode *elemNode);

/**
 * 初始条件：二叉树存在
 *
 * @param biTree 二叉树
 * @return 前序遍历成功 true
 */
bool PreOrderTravers(BiTree biTree);
/**
 * 初始条件：二叉树存在
 *
 * @param biTree 二叉树
 * @return 中序遍历成功 true
 */
bool InOrderTraversR(BiTree biTree);
bool InOrderTravers(BiTree biTree);
/**
 * 初始条件：二叉树存在
 *
 * @param biTree 二叉树
 * @return 后序遍历成功 true
 */
bool PostOrderTravers(BiTree biTree);

/**
 * 初始条件：二叉树存在
 *
 * @param biTree 二叉树
 * @return 层序遍历成功 true
 */
bool LevelOrderTravers(BiTree biTree);

/**
 * 初始条件：二叉树存在
 *
 * @param biTree 二叉树
 * @param nodeElem
 * @return
 */
BiTNode *FindNode(BiTree biTree, BiTNode *elemNode);

#endif//DATASTRUCTWITHC_BINARYTREE_H
