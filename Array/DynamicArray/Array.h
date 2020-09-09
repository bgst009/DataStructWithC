//
// Created by bgst on 2020/9/9.
//

#ifndef DATASTRUCTWITHC_ARRAY_H
#define DATASTRUCTWITHC_ARRAY_H
#define INCREMENT 20

typedef struct MyArray Array;
typedef int ElementType;


Array initArray(int size);
void getElement(Array array, int number, ElementType* element);
void addElement(Array* array, ElementType element);


#endif//DATASTRUCTWITHC_ARRAY_H
