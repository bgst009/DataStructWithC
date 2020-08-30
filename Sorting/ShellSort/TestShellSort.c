//
// Created by bgst on 2020/8/30.
//

#include "Helper.h"
#include "ShellShort.h"
int main() {

  int size = 10;
  ElementType *arr = generateRandomArray(size, 1, 1000);
  printArray(arr, size);
  testSort("ShellShort", ShellShort, arr, size);
  free(arr);
  return 0;
}
