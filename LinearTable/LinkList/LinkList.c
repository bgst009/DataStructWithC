//
// Created by 14991 on 2020/8/22.
//

#include "LinkList.h"

#include <unistd.h>

#include "../../Stack/LinkStack/LinkStack.h"

void createListHead(LinkList *L, int n) {
    LNode *p;
    int i;
    int negtive = 1;
    //带头结点的单链表 L (L 就是头节点)
    *L = (LinkList) malloc(sizeof(LNode));
    (*L)->next = NULL;
    //初始化随机树种子
    srand(time(0));
    for (int j = 0; j < n; ++j) {
        //        negtive = -negtive;
        p = (LNode *) malloc(sizeof(LNode));
        p->data = negtive * rand() % 15 + 1;//0-100;
        p->next = (*L)->next;
        (*L)->next = p;
    }

    //    sleep(2);
}

void createDoubleList(DLinkList L, int n) {
    createCirculateDoubleListTail(L, n);
    L->Prior->Next = NULL;
    L->Prior = NULL;
}

void createCirculateDoubleListTail(DLinkList L, int n) {
    DNode *p;
    L->Next = L;

    L->Prior = L;

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        p = (DNode *) malloc(sizeof(DNode));
        p->data = rand() % 25 + 1;

        p->Next = L->Prior->Next;
        p->Prior = L->Prior;
        L->Prior->Next = p;
        L->Prior = p;
    }
}

void createSymmetricDoubleList(DLinkList L, int n) {
    DNode *p;
    L->Next = L;


    LinkStack S;
    InitStack_LS(&S);
    ElemType elem;

    L->Prior = L;

    srand(time(NULL));
    for (int i = 0; i < n / 2; i++) {
        p = (DNode *) malloc(sizeof(DNode));
        p->data = rand() % 15 + 1;

        Push_LS(&S, p->data);

        p->Next = L->Prior->Next;
        p->Prior = L->Prior;
        L->Prior->Next = p;
        L->Prior = p;
    }

    if (n % 2 != 0) {
        Push_LS(&S, n);
    }

    for (int i = n / 2; i < n; ++i) {
        p = (DNode *) malloc(sizeof(DNode));

        Pop_LS(&S, &elem);

        p->data = elem;

        p->Next = L->Prior->Next;
        p->Prior = L->Prior;
        L->Prior->Next = p;
        L->Prior = p;
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


void createCircleListTail(LinkList L, int n) {
    LNode *r;
    LNode *p;

    L->next = L;
    r = L;


    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        p = (LNode *) malloc(sizeof(LNode));
        p->data = rand() % 100 + 1;//0-100;
        p->next = r->next;
        r->next = p;
        r = p;
    }
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

bool ListTraverse_DL(DLinkList L) {
    DNode *p;
    p = L->Next;
    int j = 0;
    while (p != L) {
        printf(" %d ", p->data);
        p = p->Next;

        if (p == NULL) {
            printf("\n");
            return true;
        }

        ++j;
        if (j % 20 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    return true;
}

bool ListTraverse_L(LinkList *L) {
    LNode *p;
    p = (*L)->next;
    //计数器
    int j = 0;

    while (p->next) {
        printf("%d->", p->data);
        p = p->next;

        //循环单链表
        if (p == (*L)) {
            printf("\n");
            return false;
        }

        ++j;
        if (j % 20 == 0) {
            printf("\n");
        }
    }

    printf("%d", p->data);
    printf("\n");
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
LinkList ReverseList_Recursive_L(LinkList L, LinkList list) {
    if (L == NULL) {//递归终止
        return list;
    }

    LNode *p = L;
    L = ReverseList_Recursive_L(L->next, list);
    L->next = p;

    return p;
}
LinkList ReverseList(LinkList L) {
    LNode *p = L->next;
    LinkList list = (LinkList) malloc(sizeof(LNode));
    p = ReverseList_Recursive_L(p, list);
    p->next = NULL;
    return list;
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
void UnionLinkList(LinkList L1, LinkList L2) {
    LNode *pa, *pb;
    LNode *aTmp, *bTmp;
    LinkList L3;


    pa = L1->next;
    pb = L2->next;
    L3 = L1;
    L3->next = NULL;

    while (pa->next != NULL && pb->next != NULL) {
        if (pa->data == pb->data) {
            //将 L1中相同的节点插入到 L3中
            aTmp = pa;
            pa = pa->next;
            aTmp->next = L3->next;
            L3->next = aTmp;

            //删除 L2中相同的节点
            bTmp = pb;
            pb = pb->next;
            free(bTmp);
        } else if (pa->data > pb->data) {
            bTmp = pb;
            pb = pb->next;
            free(bTmp);
        } else {//pa->data < pb->data
            aTmp = pa;
            pa = pa->next;
            free(aTmp);
        }
    }

    while (pa) {
        aTmp = pa;
        pa = pa->next;
        free(aTmp);
    }
    while (pb) {
        bTmp = pb;
        pb = pb->next;
        free(bTmp);
    }

    free(L2);
}
bool symmetry(DLinkList L) {
    DNode *front = L->Next;
    DNode *rear = L->Prior;

    for (; rear != front && rear->Next != front; rear = rear->Prior, front = front->Next) {
        if (rear->data != front->data)
            return false;
    }

    return true;
}
void connectDLinkList(DLinkList L1, DLinkList L2) {

    if (L1->Next == NULL || L2->Next == NULL)
        return;

    L2->Prior->Next = L1->Prior->Next;//把L2 的尾节点的后继改为L1 尾节点的后继
    //将L2 的首元节点和L1 的尾节点链接起来
    L2->Next->Prior = L1->Prior;//把L2 的首元节点的前驱改为L1 的尾节点
    L1->Prior->Next = L2->Next; //L1 的尾节点的后继为L2 的首元节点
    L1->Prior = L2->Prior;      //把L1 的尾节点指向L2 的尾节点
}

void connectLindList(LinkList L1, LinkList L2) {
    LNode *p;
    p = L1->next;
    while (p->next) {
        p = p->next;
    }
    p->next = L2->next;
}
void deleteSmall(LinkList L) {
    LNode *p, *pre;
    LNode *min, *preMin;

    while (L->next != L) {//not empty
        pre = L;
        p = L->next;
        min = p;
        preMin = pre;

        while (p != L) {//loop findMin
            if (p->data < min->data) {
                min = p;
                preMin = pre;
            }
            p = p->next;
            pre = pre->next;
        }
        printf(" %d", min->data);//print min
        preMin->next = min->next;//delete min
        free(min);
    }
    free(L);//delete LinkList
}
DNode *Locate(DLinkList L, ElemType elem) {
    if (L->Next == NULL) {
        printf("\n DLinkList is empty\n");
        return L;
    }

    DNode *p, *q;
    p = L->Next;

    while (p && p->data != elem) {
        p = p->Next;
    }

    if (!p) {
        printf("\n fail to find \n");
        //        exit(0);
        return L;
    } else {
        p->freq++;

        //delete p But not free
        if (p->Next != NULL) {
            p->Next->Prior = p->Prior;
        }
        p->Prior->Next = p->Next;

        //insert into right place
        q = p->Prior;
        //find where to insert
        while (q != L && q->freq <= p->freq) {
            q = q->Prior;
        }

        //Now find, So insert into right place
        p->Next = q->Next;
        q->Next->Prior = p;
        p->Prior = q;
        q->Next = p;
    }

    return p;
}
bool findLastK(LinkList L, int k) {
    //带头结点
    if (L->next == NULL) {
        perror("findLastK failed L is empty");
        return false;
    }

    LNode *p, *q;
    int count = 0;

    p = q = L->next;
    while (p != NULL) {
        if (count < k) count++;
        else
            q = q->next;
        p = p->next;
    }
    if (count < k) {
        printf("\n Not Find \n");
        return false;
    }

    printf("\n Find last %dth element is: %d \n", k, q->data);
    return true;
}
LNode *findCoNode(LinkList L1, LinkList L2) {

    if (L1->next == NULL || L2->next == NULL) {
        perror("L1 or L2 is Empty");
        return NULL;
    }

    int length1 = listLength(L1);
    int length2 = listLength(L2);

    LNode *p1, *p2;
    for (p1 = L1; length1 > length2; --length1) {
        p1 = p1->next;
    }
    for (p2 = L2; length2 > length1; --length2) {
        p2 = p2->next;
    }

    while (p1->next != NULL && p1->next != p2->next) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1->next;
}
int listLength(LinkList list) {
    int res = 0;
    LNode *p = list->next;
    while (p) {
        p = p->next;
        ++res;
    }
    return res;
}
void deleteRepeat(LinkList list, int n) {
    if (list == NULL) {
        perror("list is empty");
        return;
    }

    int val[n + 1];
    for (int i = 0; i < n + 1; i++) {
        val[i] = 0;
    }

    LNode *pre;
    pre = list;

    while (pre->next != NULL) {
        if (val[abs(pre->next->data)] != 0) {
            LNode *p = pre->next;
            pre->next = p->next;
            free(p);
        } else {//val[pre->next->data] == 0,
            val[abs(pre->next->data)]++;
            pre = pre->next;
        }
    }
}
LNode *findLoopStart(LinkList list) {

    LNode *fast, *slow;
    fast = list->next;
    slow = list->next;

    //快慢指针移动
    while (slow != NULL && fast->next != NULL) {
        slow = slow->next;      //走一步
        fast = fast->next->next;//走两步
        if (fast == slow) break;//相遇
    }

    //无环
    if (slow == NULL || fast->next == NULL) {
        return NULL;
    }

    LNode *p1 = list->next, *p2 = slow;//p1 首元节点，p2 相遇节点

    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}
LNode *findNode(LinkList list, ElemType elem) {
    if (list->next == NULL) {
        perror("list empty");
        return NULL;
    }

    LNode *p = list;
    while (p->next) {
        if (p->next->data == elem)
            break;
        else
            p = p->next;
    }
    return p->next;
}
LNode *findLastNode(LinkList list) {

    if (list->next == NULL) {
        perror("list empty");
        return NULL;
    }

    LNode *p = list;

    while (p->next) {
        p = p->next;
    }

    return p;
}
void changeList(LinkList list) {
    LNode *mid, *rear;
    rear = list->next;
    mid = list->next;

    //        while (rear->next != NULL) {//find mid node
    //            mid = mid->next;
    //            rear = rear->next;
    //            if (rear->next != NULL) {
    //                rear = rear->next;
    //            }
    //        }

    int length = listLength(list);
    length /= 2;
    while (length > 0) {
        mid = mid->next;
        length--;
    }

    //    printf("\n mid : %d\n", mid->data);

    rear = mid->next;
    mid->next = NULL;

    LinkList list2 = (LinkList) malloc(sizeof(LNode));
    list2->next = rear;

    rear = ReverseList(list2);
    //    ListTraverse_L(&rear);

    LNode *p1, *p2, *p;
    p1 = list->next;
    p2 = rear->next;

    while (p2) {
        p = p2->next;//temporary storage
        p2->next = p1->next;
        p1->next = p2;
        p1 = p2->next;
        p2 = p;
    }
}
