//
// Created by bgst on 2020/8/28.
//

#ifndef DATASTRUCTWITHC_BINARYSEARCHTREE_H
#define DATASTRUCTWITHC_BINARYSEARCHTREE_H

#include "../header.h"
#include "./TreeNode.h"

SearchTree MakeEmpty(SearchTree T);

Position Find(ElementType X, SearchTree T);

Position FindMin(SearchTree T);

Position FindMax(SearchTree T);

SearchTree Insert(ElementType X, SearchTree T);

SearchTree Delete(ElementType X, SearchTree T);

ElementType Retrieve(Position P);

void InOrder(SearchTree T);

#endif //DATASTRUCTWITHC_BINARYSEARCHTREE_H
