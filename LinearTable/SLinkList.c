//
// Created by 14991 on 2020/8/22.
//

#include "SLinkList.h"


bool InitList_SL(SLinkList space) {
    int i;

    //初始化每一个的后继为顺序的下一个（除了最后一个）
    for (i = 0; i < MAXSIZE - 1; ++i) {
        space[i].cur = i + 1;
    }
    //最后一个的后继为 0
    space[MAXSIZE - 1].cur = 0;
    return true;
}

int Malloc_SL(SLinkList space) {
    //备用元素的第一个下标
    int i = space[0].cur;

    if (space[0].cur) {
        //要往出哪一个，就要把它的下一个拿来备用
        space[0].cur = space[i].cur;
    }

    return i;
}

bool ListInsert_SL(SLinkList Space, int i, ElemType e) {
    //最后一个元素的下标
    int k = MAXSIZE - 1;

    //边界合法性判断
    if (i < 1 || i > ListLength_SL(Space) + 1) {
        return false;
    }

    //获得空闲分量的下标
    int j = Malloc_SL(Space);

    if (j) {
        Space[j].data = e;
        int l;
        //找到 i 个元素之前的位置
        for (l = 1; l <= i - 1; ++l) {
            k = Space[k].cur;
        }

        Space[j].cur = Space[k].cur;
        Space[k].cur = j;

        return true;
    }
    return false;
}

bool ListDel_SL(SLinkList Space, int i) {
    //边界合法性判断
    if (i < 1 || i > ListLength_SL(Space) + 1) {
        return false;
    }
    //最后一个元素的下标
    int k = MAXSIZE - 1;

    //要删除元素的下标
    int j;

    //找到 i 个元素之前的位置
    for (j = 1; j <= i - 1; ++j) {
        k = Space[k].cur;
    }
    j = Space[k].cur;
    Space[k].cur = Space[j].cur;
    Free_SL(Space, j);

    return true;
}

int ListLength_SL(SLinkList space) {
    int j = 0;
    int i = space[MAXSIZE - 1].cur;
    while (i) {
        i = space[i].cur;
        j++;
    }
    return j;
}

void Free_SL(SLinkList space, int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

bool ListTraverse_SL(SLinkList L) {
    if (L[MAXSIZE - 1].cur == 0)
        return false;

    int i = L[MAXSIZE - 1].cur;
    int j = 0;
    while (i) {
        printf(" %d ", L[i].data);
        i = L[i].cur;

        ++j;
        if (j % 10 == 0)
            printf("\n");
    }

}