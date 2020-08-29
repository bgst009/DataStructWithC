//
// Created by bgst on 2020/8/29.
//

#include "ShellShort.h"
#include "../SortTestHelper/Template.h"

bool ShellShort(ElementType *a, int N) {

    //参数合法性判断
    if (a == NULL || N <= 0) {
        printf("\n ShellShort ERROR \n");
        return false;
    }

//    int i, j, increment;
//    ElementType tmp;
//
//    for (increment = size / 2; increment > 0; increment /= 2) {
//        for (i = increment; i < size; i++) {
//            tmp = array[i];
//            for (j = i; j >= increment; j += increment)
//                if (tmp < array[j - increment])
//                    array[j] = array[j - increment];
//                else
//                    break;
//
//            array[i] = tmp;
//        }
//    }

    int h = 1;
    while (h < N / 3)h = 3 * h + 1;//1,4,13,40

    while (h >= 1) {
        for (int i = h; i < N; ++i) {
            for (int j = i; j >= h && (a[j - h] > a[j]); j -= h) {
                exchange(a, j - h, j);
            }
        }
        h = h / 3;
    }


    return true;
}

bool ShellShortWithoutExchange(ElementType *array, int size) {
    //参数合法性判断
    if (array == NULL || array <= 0) {
        printf("\n ShellShort ERROR \n");
        return false;
    }

    int h = 1;
    while (h < N / 3)h = 3 * h + 1;//1,4,13,40

    while (h >= 1) {
        for (int i = h; i < N; ++i) {
            for (int j = i; j >= h && (a[j - h] > a[j]); j -= h) {
                exchange(a, j - h, j);
            }
        }
        h = h / 3;
    }
    int i, j, increment;
    ElementType tmp;

    while (increment < size / 3) increment = 3 * increment + 1;

    for (increment; increment >= 1; increment /= 3) {
        for (i = increment; i < size; i++) {
            tmp = array[i];
            for (j = i; j >= increment; j += increment)
                if (tmp < array[j - increment])
                    array[j] = array[j - increment];
                else
                    break;

            array[i] = tmp;
        }
    }
}
