//
// Created by 14991 on 2020/8/16.
//


#include <assert.h>
#include "SqList.h"

int main() {
    printf("H e l l o , W o r l d ! \n");

//    test_SqList();

//    test_LinkList();

    test_SLinkList();
    return 0;
}

void test_SqList() {
    printf("\n/***** test SqList *****/\n");

    SqListDynamic Sq;
    if (InitList_Sq(&Sq))
        printf("\nInitial Successful\n");
    else
        printf("\nInitial Fail\n");

    for (int i = 0; i < 20; ++i) {
        ListInsert_Sq(&Sq, i + 1, i);
    }

    printf("\nList Length is %d\n", ListLength_Sq(Sq));
    ElemType elemType, pre_e, next_e, del_e;
    int index;
    GetElem_Sq(Sq, 5, &elemType);
    PriorElem_Sq(Sq, 4, &pre_e);
    NextElem_Sq(Sq, 4, &next_e);
    LocateElem_Sq(Sq, 4, &index);
    printf("\n第%d个元素是%d\n", 5, elemType);
    printf("\n第%d个元素前驱%d\n", 5, pre_e);
    printf("\n第%d个元素后继%d\n", 5, next_e);
    printf("\n%d是第 %d 个元素\n", 4, next_e);
    ListTraverse_Sq(Sq);
    ListDelete_Sq(&Sq, 5, &del_e);
    printf("\n第%d个元素是%d\n", 5, elemType);
    ListTraverse_Sq(Sq);

    ClearList_Sq(&Sq);
    DestroyList_Sq(&Sq);
    ListTraverse_Sq(Sq);
}

void test_LinkList() {
    LinkList L;
    createListHead(&L, 20);
    ListTraverse_L(&L);

//    ElemType elemType = 5;
//    ListInsert_L(L, 5, elemType);
//    ListTraverse_L(&L);
//    ListDelete_L(L, 5, &elemType);
//    printf("\n %d \n", elemType);

    LinkList L1;
    createListTail(&L1, 19);
    ListTraverse_L(&L1);

//    ElemType elemType1 = 5;
//    ListInsert_L(L1, 5, elemType1);
//    ListTraverse_L(&L1);
//    ListDelete_L(L1, 5, &elemType1);
//    printf("\n %d \n", elemType1);
}

void test_SLinkList() {
    SLinkList SL;
    InitList_SL(SL);

    srand(time(0));
    for (int i = 0; i < 100; ++i) {
        ListInsert_SL(SL, i + 1, rand() % 100 + 1);
    }

    ListTraverse_SL(SL);
}

bool InitList_Sq(SqListDynamic *L) {
    L->data = (ElemType *) malloc(ListInitSize * sizeof(ElemType));
    if (L->data) {
        L->listSize = 100;
        L->length = 0;
        return true;
    } else
        return false;
}

bool InitList_SL(SLinkList *space) {
    int i = 0;
    for (i = 0; i < MAXSIZE - 1; ++i) {
        (*space[i]).cur = i + 1;
    }
    (*space[MAXSIZE - 1]).data = 0;
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
        for (l = 1; l < i; ++l) {
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
    int j = 0;

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

void createListHead(LinkList *L, int n) {
    LNode *p;
    int i;
    //带头结点的单链表 L (L 就是头节点)
    *L = (LinkList) malloc(sizeof(LNode));
    (*L)->next = NULL;
    //初始化随机树种子
    srand(time(0));
    for (int j = 0; j < n; ++j) {
        p = (LNode *) malloc(sizeof(LNode));
        p->data = rand() % 100 + 1;//0-100;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void createListTail(LinkList *L, int n) {
    //r 为指向尾部的指针
    LNode *r;
    LNode *p;
    int i;
    //带头结点的单链表 L (L 就是头指针)
    *L = (LinkList) malloc(sizeof(LNode));
    (*L)->next = NULL;
    r = *L;
    //初始化随机树种子
    srand(time(0));
    for (int j = 0; j < n; ++j) {
        p = (LNode *) malloc(sizeof(LNode));
        p->data = rand() % 100 + 1;//0-100;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
//DestroyList
bool DestroyList_Sq(SqListDynamic *L) {
    free(L->data);
    L->listSize = 0;
    L->length = 0;

    if (!L->data)
        return true;
    else
        return false;
}
//ClearList
bool ClearList_Sq(SqListDynamic *L) {
    L->length = 0;
    if (L->length == 0)
        return true;
    else
        return false;
}
//ListEmpty
bool ListEmpty_Sq(SqListDynamic L) {
    if (L.data && L.length != 0) {
        return false;
    } else
        return true;
}

//ListLength
int ListLength_Sq(SqListDynamic L) {
    if (ListEmpty_Sq(L)) {
        return 0;
    } else
        return L.length;
}
//GetElem
bool GetElem_Sq(SqListDynamic L, int i, ElemType *e) {
    if (L.length == 0 || i < 0 || i > L.length) {
        return false;
    }

    *e = L.data[i - 1];
    return true;
}

bool GetElem_L(LinkList L, int i, ElemType *e) {
    //声明节点 p
    LNode *p;
    // 指向第一个节点
    p = L->next;

    //为第一个元素则直接返回
    if (i == 0) {
        *e = L->data;
        return true;
    }
    if (i < 1) {
        printf("\n i 值异常 \n");
        return false;
    }

    // j 计数器
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }

    //第 i 个元素不存在；
    if (!p || j > i) {
        return false;
    }
    //去除第 i 个元素
    *e = L->data;

    return p;
}
//LocateElem
bool LocateElem_Sq(SqListDynamic L, ElemType e, int *index) {
    if (!ListEmpty_Sq(L)) {
        for (int i = 0; i < L.length; i++) {
            if (L.data[i] == e) {
                *index = i;
                return true;
            }
        }
        return false;
    } else
        return false;
}
//PriorElem
bool PriorElem_Sq(SqListDynamic L, ElemType cur_e, ElemType *pre_e) {
    if (!ListEmpty_Sq(L)) {
        for (int i = 1; i < L.length; i++) {
            if (L.data[i] == cur_e) {
                *pre_e = L.data[i - 1];
                return true;
            }
        }
        return false;
    } else
        return false;
}
//NextElem
bool NextElem_Sq(SqListDynamic L, ElemType cur_e, ElemType *next_e) {
    if (!ListEmpty_Sq(L)) {
        for (int i = L.length - 2; i >= 0; --i) {
            if (L.data[i] == cur_e) {
                *next_e = L.data[i + 1];
                return true;
            }
        }
        return false;
    } else
        return false;
}
//ListInsert
bool ListInsert_Sq(SqListDynamic *L, int i, ElemType e) {
    //在某个元素前插入元素的 i 合法性判断
    if (i < 1 || i > L->length + 1) {
        printf("\n插入位置非法\n");
        return false;
    }

    if (L->length >= L->listSize) {//不够重新分配内存
        ElemType *newBase = (ElemType *) realloc(L->data, (L->listSize + ListIncrement) * sizeof(ElemType));
        if (!newBase)//申请失败
            return false;
        L->data = newBase;//新的基地址
        L->listSize += ListIncrement;//新的总容量
    }
    //先移开
    if (i <= L->length) {//插入元素不在表尾
        for (int j = L->length - 1; j >= i - 1; --j) {
            L->data[j + 1] = L->data[j];
        }
    }
    //再插入
    L->data[i - 1] = e;
    L->length++;
    return true;
}

bool ListInsert_L(LinkList L, int i, ElemType e) {
    //声明节点 p
    LNode *p;
    // 指向第一个节点
    p = L->next;
    int j = 1;

    //looking for elem i
    while (j < i && p) {
        p = p->next;
        ++j;
    }

    // the i is not exist
    if (!p || j > i) {
        printf("\nNo such Elem!!!\n");
        return false;
    }

    //creat a new Node of List
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}
//ListDelete
bool ListDelete_Sq(SqListDynamic *L, int i, ElemType *e) {
    //i 的合法值 [1...L->length]
    if (i < 1 || i > L->length || ListEmpty_Sq(*L)) {
        return false;
    }

    *e = L->data[i - 1];

    if (i < L->length) {//删除元素不在表尾
        for (int k = i; k < L->length; ++k) {
            L->data[k - 1] = L->data[k];
        }
    }
    L->length--;
    return true;
}

bool ListDelete_L(LinkList L, int i, ElemType *e) {
    //声明节点 p
    LNode *p;
    // 指向第一个节点
    p = L->next;
    int j = 1;

    //looking for elem i
    while (j < i && p) {
        p = p->next;
        ++j;
    }

    // the i is not exist
    if (!p || j > i) {
        printf("\nNo such Elem!!!\n");
        return false;
    }

    //temp Node
    LNode *q = p->next;
    p->next = q->next;

    *e = q->data;
    //del node p
    free(q);

    return true;
}
//ListTraverse
bool ListTraverse_Sq(SqListDynamic L) {
    if (L.length == 0) {
        printf("\n empty list\n");
        return false;
    }

    for (int i = 0; i < L.length; ++i) {
        if (i % 10 == 0)
            printf("\n");
        printf(" %d ", L.data[i]);
    }
    printf("\n");

    return true;
}

bool ListTraverse_L(LinkList *L) {
    printf("\n ListTraverse_L \n");

    LNode *p;
    p = (*L)->next;
    //计数器
    int j = 0;

    while (p) {
        printf(" %d ", p->data);
        p = p->next;
        ++j;
        if (j % 20 == 0) {
            printf("\n");
        }
    }
}

bool ListTraverse_SL(SLinkList L) {
    if (L[MAXSIZE - 1].cur == 0)
        return false;

    int i = L[MAXSIZE - 1].cur;
    int j = 0;
    while (i) {
        i = L[i].cur;
        printf(" %d ", L[i].data);
        ++j;
    }

}
