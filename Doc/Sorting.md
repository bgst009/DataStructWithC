# Sorting

## SelectionSort

> 排序过程中每一个元素的最终位置已经确定

- 思想:在整个数组中找到最小的元素并且放到合适的位置

## InsertionSort

> 只是前半部分的暂时排序结果

- 思想:在前半部的找到当前下标对应元素的位置

- 可以不用每次都交换而是向后移动，最后把元素放到正确位置

- 有序数组 O(n);



### ShellSort

> 1. 将无序序列划分成若干个不同的子序列
> 2. 对每一个子序列进行插入排序
> 3. 对完成对若干子序列的排序，改变增量继续进行 1 直到有序

-  [code-example](../Sorting/ShellSort/ShellShort.c)
  
  ## MergeSort
  
  > [l....mid],[mid+1...r]