//
// Created by bgst on 2020/8/26.
//

#include "test.h"

int main() {
    testBT();

    return 0;
}


void testBT() {

    printf("\n 初始化一颗空树 \n");
    BiTree init;
    InitBiTree(&init);
    Visit(Root(init));
    printf("\n\n");



    BiTree Tree;
    CreateBiTree(&Tree);
    setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区

//    ABC##D##E##
    printf("\n先序遍历\n");
    PreOrderTravers(Tree);
    printf("\n中序遍历\n");
    InOrderTravers(Tree);
    printf("\n后序遍历\n");
    PostOrderTravers(Tree);
    printf("\n层序序遍历\n");
    LevelOrderTravers(Tree);

    BiTNode *biTNode = (BiTNode *) malloc(sizeof(BiTNode));
    biTNode->data = 'B';
    biTNode->rchild = biTNode->lchild = NULL;

    BiTNode *leftChild, *rightChild, *leftSibling, *rightSibling;
    leftChild = LeftChild(Tree, biTNode);
    leftSibling = LeftSibling(Tree, biTNode);
    rightSibling = RightSibling(Tree, biTNode);
    rightChild = RightChild(Tree, biTNode);


    printf("\n %c 的左孩子 %c,右孩子 %c \n", biTNode->data, leftChild->data, rightChild->data);
    printf("\n %c 的左兄弟 %c,右兄弟 %c \n", biTNode->data, leftSibling->data, rightSibling->data);

    Assign(Tree, biTNode, 'G');
    printf("\n层序序遍历\n");
    LevelOrderTravers(Tree);
    biTNode->data = 'G';

    printf("\n %c \n", Value(Tree, biTNode));


    printf("\n 为树中的节点添加子树 \n");

    //HIGK#####
    BiTree new;
    CreateBiTree(&new);
    setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区

    InsertChild(Tree, biTNode, 1, new);
    printf("\n层序序遍历\n");
    LevelOrderTravers(Tree);
    printf("\n\n");


    ClearBiTree(&Tree);
    Visit(Root(Tree));

    DestroyBiTree(&Tree);
    Visit(Root(Tree));
}
