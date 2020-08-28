//
// Created by bgst on 2020/8/26.
//

#include "BinaryTree.h"

#include "./LinkQueue/LinkQueue.h"

int Max(int depth, int depth1);

bool InitBiTree(BiTree *biTree) {
    if (!((*biTree) = (BiTree) malloc(sizeof(BiTNode))))
        return false;
    (*biTree)->data = '#';
    (*biTree)->lchild = (*biTree)->rchild = NULL;
    return true;
}

bool DestroyBiTree(BiTree *biTree) {
    if (*biTree) {
        if ((*biTree)->lchild)
            DestroyBiTree(&((*biTree)->lchild));
        if ((*biTree)->rchild)
            DestroyBiTree(&((*biTree)->rchild));

        free(*biTree);
        *biTree = NULL;
//        printf("\n销毁成功!\n");

        return true;
    }

    return false;
}

bool CreateBiTree(BiTree *biTree) {


    char ch;
    scanf("%c", &ch);

    if (ch == '#') {
        *biTree = NULL;
    } else {
        (*biTree) = (BiTNode *) malloc(sizeof(BiTNode));
        //动态分配内存失败
        if (!(*biTree)) {
            printf("\n No Space !!\n");
            return false;
        }
        //生成根节点
        (*biTree)->data = ch;
        (*biTree)->rchild = NULL;
        (*biTree)->rchild = NULL;
        //构造左子树
//        printf("\n建立左子树\n");
        CreateBiTree(&((*biTree)->lchild));
        //构造右子树
//        printf("\n建立右子树\n");
        CreateBiTree(&((*biTree)->rchild));
    }


    return true;
}

bool BiTreeEmpty(BiTree biTree) {
    return (biTree == NULL) ? true : false;
}

BiTree Root(BiTree biTree) {
    if (BiTreeEmpty(biTree)) {
        printf("\n Tree is Empty!!\n");
        return NULL;
    } else {
        return biTree;
    }
}

BiTNode *FindNode(BiTree biTree, BiTNode *elemNode) {
    if (BiTreeEmpty(biTree)) {
        printf("\n Tree is Empty \n");
        return NULL;
    }

    if (biTree->data == elemNode->data || biTree == elemNode) {
        return biTree;
    }

    BiTNode *return_Node;

    return_Node = FindNode(biTree->lchild, elemNode);
    if (return_Node)
        return return_Node;
    return_Node = FindNode(biTree->rchild, elemNode);
    if (return_Node)
        return return_Node;

    return NULL;
}

TElemType Value(BiTree biTree, BiTNode *elemNode) {
    return FindNode(biTree, elemNode)->data;
}

bool Assign(BiTree biTree, BiTNode *elemNode, TElemType value) {
    if (!(elemNode = FindNode(biTree, elemNode))) {
        printf("\n Can not find node!!! \n");
        return false;
    }

    elemNode->data = value;

    return true;

}

BiTNode *Parent(BiTree biTree, BiTNode *elemNode) {
    if (BiTreeEmpty(biTree) || (biTree->lchild == NULL && biTree->rchild == NULL)) {
        printf("\n Tree is Empty or Only Have root \n");
        return NULL;
    }

    //可以找到父亲节点
    if (biTree->rchild == elemNode || biTree->lchild == elemNode
        || biTree->rchild->data == elemNode->data || biTree->lchild->data == elemNode->data) {
        return biTree;
    }
    BiTNode *return_Node;

    return_Node = Parent(biTree->lchild, elemNode);
    if (return_Node)
        return return_Node;
    return_Node = Parent(biTree->rchild, elemNode);
    if (return_Node)
        return return_Node;

    return NULL;
}

BiTNode *LeftChild(BiTree biTree, BiTNode *elemNode) {
    return FindNode(biTree, elemNode)->lchild;
}

BiTNode *RightChild(BiTree biTree, BiTNode *elemNode) {
    return FindNode(biTree, elemNode)->rchild;
}

BiTNode *LeftSibling(BiTree biTree, BiTNode *elemNode) {
    BiTNode *node = FindNode(biTree, elemNode);
    BiTNode *parent = Parent(biTree, node);

    //没有找到，或者该节点为父亲节点的左孩子
    if (!parent || parent->lchild == node) {
        parent = (BiTree) malloc(sizeof(BiTree));
        parent->data = '#';
        parent->rchild = parent->lchild = NULL;
        return parent;
    }

    return parent->lchild;


}

BiTNode *RightSibling(BiTree biTree, BiTNode *elemNode) {
    BiTNode *node = FindNode(biTree, elemNode);
    BiTNode *parent = Parent(biTree, elemNode);

    //没有找到，或者该节点为父亲节点的右孩子
    if (!parent || parent->rchild == node) {
        parent = (BiTree) malloc(sizeof(BiTree));
        parent->data = '#';
        parent->rchild = parent->lchild = NULL;
        return parent;
    }

    return parent->rchild;
}

bool InsertChild(BiTree biTree, BiTNode *p, int LR, BiTNode *c) {
    p = FindNode(biTree, p);

    //c 非空
    if (c) {
        //right
        if (LR) {
            c->rchild = p->rchild;
            p->rchild = c;
        } else {
            c->rchild = p->lchild;
            p->lchild = c;
        }

        return true;
    } else {
        return false;
    }
}

bool Visit(BiTNode *elemNode) {
    if (BiTreeEmpty(elemNode)) {
        return false;
    }

    printf(" %c ", elemNode->data);
    return true;
}

bool PreOrderTravers(BiTree biTree) {
    if (BiTreeEmpty(biTree)) {
        return false;
    }

    Visit(biTree);
    PreOrderTravers(biTree->lchild);
    PreOrderTravers(biTree->rchild);

    return true;
}

bool InOrderTravers(BiTree biTree) {
    if (BiTreeEmpty(biTree)) {
        return false;
    }

    InOrderTravers(biTree->lchild);
    Visit(biTree);
    InOrderTravers(biTree->rchild);

    return true;
}

bool PostOrderTravers(BiTree biTree) {
    if (BiTreeEmpty(biTree)) {
        return false;
    }

    PostOrderTravers(biTree->lchild);
    PostOrderTravers(biTree->rchild);
    Visit(biTree);

    return true;

}

bool LevelOrderTravers(BiTree biTree) {
    //空树
    if (BiTreeEmpty(biTree)) {
        printf("\n Tree is Empty \n");
        return false;
    }

    //只有根节点
    if (biTree->lchild == NULL && biTree->rchild == NULL) {
        printf("\n %c \n", biTree->data);
        return true;
    }

    LinkQueue linkQueue;
    InitQueue_LQ(&linkQueue);

    BiTNode *p;

    EnQueue_LQ(&linkQueue, biTree);

    while (!QueueEmpty_LQ(&linkQueue)) {
        DeQueue_LQ(&linkQueue, &p);
        Visit(p);
        if (p->lchild) {
            EnQueue_LQ(&linkQueue, p->lchild);
        }
        if (p->rchild) {
            EnQueue_LQ(&linkQueue, p->rchild);
        }
    }

    return true;
}

bool ClearBiTree(BiTree *biTree) {
    if (DestroyBiTree(biTree)) {
        if (!((*biTree) = (BiTree) malloc(sizeof(BiTNode))))
            return false;
        (*biTree)->data = '#';
        (*biTree)->lchild = (*biTree)->rchild = NULL;
        return true;
    } else {
        return false;
    }
}

int BiTreeDepth(BiTree biTree) {
    if (biTree == NULL)
        return 0;
    else
        return 1 + Max(BiTreeDepth(biTree->rchild), BiTreeDepth(biTree->lchild));
}

int Max(int depth, int depth1) {
    return depth >= depth1 ? depth : depth1;
}



