/*************************************************************************
	> File Name: algorithm.h
	> Author: liulianglu
	> Description: The base of all the algorithm.
        It's convenient to test.
	> Created Time: Thu 21 Sep 2017 11:55:51 PM EDT
 ************************************************************************/

#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#define end_macro(v) sizeof(v)/sizeof(int) - 1
#define num_macro(v) sizeof(v)/sizeof(int)


//下面几个算法主要体现分治的思想。
int binary_search(int* des, int begin, int end, int key);

int quick_sort  (int* des, int begin, int end);
int merge_sort  (int* des, int begin, int end);
int heap_sort   (int* des, int begin, int end);


//private info
int merge(int*v, int begin, int middle, int end, int* adjuvant);


long long fibonaci(int n);

template<typename T>
void merge_ordered  (T* des, T* src1, int len1, 
        T* src2, int len2,
        char (*predicate)(T, T));
/*
inline void swap(int* front, int* end)
{
    int temp = *front;
    *front = *end;
    *end = temp;
}

*/
#endif
