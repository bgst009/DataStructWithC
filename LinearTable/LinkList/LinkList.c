//
// Created by 14991 on 2020/8/22.
//

#include "LinkList.h"

#include "../../Stack/LinkStack/LinkStack.h"

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

void createIncreaseListHead(LinkList *L, int n) {
    LNode *p;
    int i;
    ElemType pre_elem = 0, elem;
    //带头结点的单链表 L (L 就是头节点)
    *L = (LinkList) malloc(sizeof(LNode));
    (*L)->next = NULL;
    for (int j = 0; j < n; ++j) {
        p = (LNode *) malloc(sizeof(LNode));
        elem = rand() % 2;
        if (elem)
            p->data = pre_elem;
        else
            p->data = j;
        pre_elem = j;
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
        p->next = NULL;
        r->next = p;
        r = p;
    }
    r->next = NULL;
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

bool ListTraverse_L(LinkList *L) {
    //    printf("\n ListTraverse_L \n");

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

LinkList ReverseList_L(LinkList L) {
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while (r != NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}

LinkList ReverseList_L_2(LinkList L) {
    LNode *p, *r;
    p = L->next;
    L->next = NULL;

    while (p != NULL) {

        r = p->next;

        p->next = L->next;
        L->next = p;

        p = r;
    }
    return L;
}

void ReversePrint_Recursive(LinkList L) {
    if (L->next != NULL) {
        ReversePrint_Recursive(L->next);
    }
    if (L != NULL)
        printf(" %d ", L->data);
}
void ReversePrint_Stack(LinkList L) {
    LinkStack S;
    InitStack_LS(&S);
    LNode *p = L->next;
    for (p; p != NULL; p = p->next) {
        Push_LS(&S, p->data);
    }
    print_LS(&S);
}
void DepartList(LinkList L, LinkList AB[2]) {

    if (IsEmpty(L)) {
        printf("\n List is empty\n");
        return;
    }
    //奇数列链表
    LinkList A = (LinkList) malloc(sizeof(LNode));
    //偶数列链表
    LinkList B = (LinkList) malloc(sizeof(LNode));
    LNode *pa, *pb;
    pb = L->next;
    pa = pb->next;
    A->next = pa;
    B->next = pb;

    while (pb != NULL && pa != NULL) {
        //pa 是最后一个节点
        if (pa->next == NULL) {
            pb->next = NULL;
            pb = pb->next;
            pa = pa->next;
            break;
        }

        //pb 是最后一个节点
        if (pb->next == NULL) {
            pb = pb->next;
            pa = pb->next;
        }

        //没有到达最后指针向后移动两个单位
        pb->next = pa->next;
        pb = pb->next;
        pa->next = pb->next;
        pa = pa->next;
    }

    AB[0] = A;
    AB[1] = B;
}
bool IsEmpty(LinkList L) {
    if (L->next == NULL)
        return true;
    return false;
}
void DeleteRepeatElement(LinkList L) {
    if (IsEmpty(L))
        return;

    LNode *cur, *c_next;
    cur = L->next;
    while (cur->next) {
        c_next = cur->next;
        if (cur->data == c_next->data) {
            cur->next = c_next->next;
            free(c_next);
        } else {
            cur = cur->next;
        }
    }
}
void MergeList(LinkList L1, LinkList L2) {
    LNode *pa, *pb;
    LNode *aTmp, *bTmp;

    pa = L1;
    pb = L2;

    while (pa->next != NULL && pb->next != NULL) {
        if (pa->next->data < pb->next->data) {
            pa = pa->next;
        } else if (pa->next->data > pb->next->data) {
            bTmp = pb->next;    //暂存下一个，后面的操作会断链
            pb->next = pa->next;//将 L2中的节点插入到 L1中
            pa->next = pb;
            pb = bTmp;//将 pb恢复
        } else {      //pa->next->data == pb->next->data
            pa = pa->next;
            pb = pb->next;
        }
    }

    // L1空了，把 L2剩余的部分接到 L1后面
    if (pa->next == NULL) {
        pa->next = pb->next;
    } else if (pb->next == NULL) {//L2空了，把 L1剩余的部分接到 L1后面
        pb->next = pa->next;
    }
}
LinkList FindSameElement(LinkList L1, LinkList L2) {
    LinkList resultList = (LinkList) malloc(sizeof(LNode));
    if (resultList == NULL) {
        perror("malloc");
        return NULL;
    }
    resultList->next = NULL;

    LNode *pa, *pb;
    LNode *aTmp, *bTmp;

    pa = L1;
    pb = L2;

    while (pa->next != NULL && pb->next != NULL) {
        //找到相同的元素，则分配一块内存来存存储
        if (pa->next->data == pb->next->data) {
            //创建新节点
            LNode *node = (LNode *) malloc(sizeof(LNode));
            node->data = pb->next->data;
            node->next = NULL;

            //头插法
            node->next = resultList->next;
            resultList->next = node;

            //向后移动工作指针
            pa = pa->next;
            pb = pb->next;
        } else if (pa->next->data > pb->next->data) {//较小的节点工作指针向后移动
            pb = pb->next;
        } else {//pa->next->data < pb->next->data
            pa = pa->next;
        }
    }

    return resultList;
}
