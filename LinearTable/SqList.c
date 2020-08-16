//
// Created by 14991 on 2020/8/16.
//


#include "SqList.h"

int main() {
    printf("H e l l o , W o r l d ! \n");

    test_SqList();

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

bool InitList_Sq(SqListDynamic *L) {
    L->data = (ElemType *) malloc(ListInitSize * sizeof(ElemType));
    if (L->data) {
        L->listSize = 100;
        L->length = 0;
        return true;
    } else
        return false;
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
        (*p).next = p;
    }
}

void createListTail(LinkList *L, int n) {
    //r 为指向尾部的指针
    LNode *r;
    LNode *p;
    int i;
    //带头结点的单链表 L (L 就是头节点)
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
