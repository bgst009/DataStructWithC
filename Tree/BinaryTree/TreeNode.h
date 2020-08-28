//
// Created by bgst on 2020/8/27.
//

#ifndef DATASTRUCTWITHC_TREENODE_H
#define DATASTRUCTWITHC_TREENODE_H

#include "../header.h"

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

#endif //DATASTRUCTWITHC_TREENODE_H
