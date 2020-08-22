//
// Created by 14991 on 2020/8/16.
//


#include <assert.h>
#include "SqList.h"

bool InitList_Sq(SqListDynamic *L) {
    L->data = (ElemType *) malloc(ListInitSize * sizeof(ElemType));
    if (L->data) {
        L->listSize = 100;
        L->length = 0;
        return true;
    } else
        return false;
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
