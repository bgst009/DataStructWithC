//
// Created by bgst on 2020/8/26.
//

#include "BinaryTree.h"

#include "./LinkQueue/LinkQueue.h"

bool InitBiTree(BiTree biTree) {

//    if (!(biTree = (BiTree) malloc(sizeof(BiTNode)))) {
//        printf("\n No space \n");
//    }

    biTree->data = '#';
    biTree->rchild = NULL;
    biTree->lchild = NULL;

    return true;
}

bool DestroyBiTree(BiTree biTree) {

}

bool CreateBiTree(BiTree *biTree) {


    char ch;
    scanf("%c", &ch);

    if (ch == '#') {
        biTree = NULL;
    } else {
        (*biTree) = (BiTNode *) malloc(sizeof(BiTNode));
        //动态分配内存失败
        if (!(*biTree)) {
            printf("\n No Space !!\n");
            return false;
        }
        //生成根节点
        (*biTree)->data = ch;
        //构造左子树
        CreateBiTree(&(*biTree)->lchild);
        //构造右子树
        CreateBiTree(&(*biTree)->rchild);
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
    } else {
        FindNode(biTree->lchild, elemNode);
        FindNode(biTree->rchild, elemNode);
    }
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
        printf("\n Tree is Empty \n");
        return NULL;
    }

    if (biTree->rchild == elemNode || biTree->lchild == elemNode
        || biTree->rchild->data == elemNode->data || biTree->lchild->data == elemNode->data) {
        return biTree;
    } else {
        Parent(biTree->lchild, elemNode);
        Parent(biTree->rchild, elemNode);
    }
}

BiTNode *LeftChild(BiTree biTree, BiTNode *elemNode) {
    return FindNode(biTree, elemNode)->lchild;
}

BiTNode *RightNode(BiTree biTree, BiTNode *elemNode) {
    return FindNode(biTree, elemNode)->rchild;
}

BiTNode *LeftSibling(BiTree biTree, BiTNode *elemNode) {
    BiTNode *left;
    left = Parent(biTree, elemNode);

    if (left == elemNode || left->data == elemNode->data) {
        return NULL;
    } else {
        return left;
    }
}

BiTNode *RightSibling(BiTree biTree, BiTNode *elemNode) {
    BiTNode *right;
    right = Parent(biTree, elemNode);

    if (right == elemNode || right->data == elemNode->data) {
        return NULL;
    } else {
        return right;
    }
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
    if (!elemNode) {
        printf("\n NULL \n");
        return false;
    }

    printf(" %c ", elemNode->data);
}

bool PreOrderTravers(BiTree biTree) {
    if (BiTreeEmpty(biTree)) {
        printf("\n Tree is Empty \n");
        return false;
    }

    Visit(biTree);
    PreOrderTravers(biTree->lchild);
    PreOrderTravers(biTree->rchild);

    return true;
}

bool InOrderTravers(BiTree biTree) {
    if (BiTreeEmpty(biTree)) {
        printf("\n Tree is Empty \n");
        return false;
    }

    InOrderTravers(biTree->lchild);
    Visit(biTree);
    InOrderTravers(biTree->rchild);

    return true;
}

bool PostOrderTravers(BiTree biTree) {
    if (BiTreeEmpty(biTree)) {
        printf("\n Tree is Empty \n");
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
}





