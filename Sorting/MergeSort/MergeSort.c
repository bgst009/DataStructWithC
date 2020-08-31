//
// Created by bgst on 2020/8/30.
//

#include "MergeSort.h"

#include "InsertionSort.h"

void C_Merge(ElementType *Array,
             ElementType *TmpArray,
             int leftPosition,
             int rightPosition,
             int rightEnd) {

    // first half    second half
    // LPos   LEnd  ,RPos       REnd
    //[left...Center,Center+1...right]
    int LeftEnd = rightPosition - 1;
    int TmpPos = leftPosition;
    int NumElements = rightEnd - leftPosition + 1;

    // main loop
    while (leftPosition <= LeftEnd && rightPosition <= rightEnd) {
        if (Array[leftPosition] <= Array[rightPosition]) {
            TmpArray[TmpPos++] = Array[leftPosition++];
        } else {
            TmpArray[TmpPos++] = Array[rightPosition++];
        }
    }

    while (leftPosition <= LeftEnd)// Copy rest of first half
        TmpArray[TmpPos++] = Array[leftPosition++];
    while (rightPosition <= rightEnd)// Copy  rest of second half
        TmpArray[TmpPos++] = Array[rightPosition++];

    // Copy the TmpArray back
    for (int i = 0; i < NumElements; rightEnd--, ++i) {
        Array[rightEnd] = TmpArray[rightEnd];
    }
}

void C_MSort(ElementType *Array, ElementType *TmpArray, int left, int right) {
    // first half    second half
    //[left...Center,Center+1...right]
    int Center;
    if (left < right) {
        Center = (left + right) / 2;
        C_MSort(Array, TmpArray, left, Center);
        C_MSort(Array, TmpArray, Center + 1, right);
        C_Merge(Array, TmpArray, left, Center + 1, right);
    }
}

void C_MergeSort(ElementType *Array, int N) {
    if (!Array || N <= 0) {
        printf("\n Invalid Parameters for C_MergeShort\n");
        return;
    }

    ElementType *TmpArray;
    if (!(TmpArray = (ElementType *) malloc(sizeof(ElementType) * N))) {
        printf("\n No space for temporary array\n");
        return;
    }

    C_MSort(Array, TmpArray, 0, N - 1);
    free(TmpArray);

    return;
}


void Merge(ElementType *Array, ElementType *aux, int lo, int mid, int hi) {
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) {
        aux[k] = Array[k];
    }

    for (int k = lo; k <= hi; k++) {
        if (i > mid)
            Array[k] = aux[j++];
        else if (j > hi)
            Array[k] = aux[i++];
        else if (aux[i] > aux[j])
            Array[k] = aux[j++];
        else
            Array[k] = aux[i++];
    }
}

void Sort(ElementType *Array, ElementType *aux, int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    Sort(Array, aux, lo, mid);
    Sort(Array, aux, mid + 1, hi);

    //如果第一部分的最大的小于第二部分最小的那么就可以不用Merge
    if (Array[mid] > Array[mid + 1])
        Merge(Array, aux, lo, mid, hi);
}

void SortWithInsertionSort(ElementType *Array, ElementType *aux, int lo, int hi) {
    //    if (hi <= lo) return;

    if (hi - lo <= 15) {
        InsertionSortInRange(Array, lo, hi);
        return;
    }

    int mid = lo + (hi - lo) / 2;
    Sort(Array, aux, lo, mid);
    Sort(Array, aux, mid + 1, hi);

    //如果第一部分的最大的小于第二部分最小的那么就可以不用Merge
    if (Array[mid] > Array[mid + 1])
        Merge(Array, aux, lo, mid, hi);
}

void MS(ElementType *Array, int size) {
    if (!Array || size <= 0) {
        printf("\n Invalid Parameters for MS\n");
        return;
    }
    ElementType *aux;

    //malloc 分配数组要右大小
    if (!(aux = (ElementType *) malloc(sizeof(ElementType) * size))) {
        printf("\n No space for temporary array\n");
        return;
    }
    Sort(Array, aux, 0, size - 1);
    free(aux);
}

void MS2(ElementType *Array, int size) {
    if (!Array || size <= 0) {
        printf("\n Invalid Parameters for MS\n");
        return;
    }
    ElementType *aux;

    //malloc 分配数组要右大小
    if (!(aux = (ElementType *) malloc(sizeof(ElementType) * size))) {
        printf("\n No space for temporary array\n");
        return;
    }
    SortWithInsertionSort(Array, aux, 0, size - 1);
    free(aux);
}