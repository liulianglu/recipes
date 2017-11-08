/*************************************************************************
	> File Name: recursion.c
	> Author: liulianglu
	> Description: some recursion algorithms, it maybe duplex. include:
    1. divide
    2. binary tree
	> Created Time: Thu 21 Sep 2017 11:58:23 PM EDT
 ************************************************************************/

#include"algorithm.h"
#include<stdio.h>
#include<stdlib.h>  //算法有空间复杂度

/*
 * 功能：   递归实现二分查找
 * src:     原数组
 * begin:   查找的开始位置
 * end:     查找的结束位置
 * des:     查找的值
 * return:  des在src中的下标，如果查找失败放回-1。
 *
 * 递归类似于循环，需要特别注意循环退出条件
 *
 */
int binary_search(int* src,int begin,  int end, int des)
{
    //1.递归先考虑结束条件——能解决的部分
    //1.1  查找失败, 以及输入非法
    if(end < begin)
        return -1;
    //1.2 查找成功。
    int middle = (end + begin)/2;           //每次更新条件
    if(des == src[middle])
    {
        return middle;
    }else if(des < src[middle])   //middle已经比较过了，要去掉。
        //使用递归也要注意避免所谓的死循环。
    {
         return binary_search(src, begin, middle -1, des);

    }else 
    {
        return binary_search(src, middle + 1, end, des);
    }
}


int quick_sort(int* des, int begin, int end)
{
    if(begin < end)
    {
        int left = begin;
        int right = end;
        int privot = des[begin];

        while(begin < end)
        {
            while((begin < end)&&des[end]>privot) end--;
            if(begin < end)
            {
                des[begin++] = des[end];
            }
            while(begin < end && privot > des[begin]) begin++;
            if(begin < end)
            {
                des[end--] = des[begin];
            }
        } 
        des[begin] = privot;


        quick_sort(des, left, begin - 1);
        quick_sort(des, begin + 1, right);
    }  
    return 0;

}


int merge(int*v, int begin, int middle, int end, int* adjuvant)
{
    //int rear    = middle - begin + 1;
    //int front   = end - middle;

    int i = 0;
    for(i = begin; i <= end; i++)
    {
        adjuvant[i] = v[i];
    }
    int rbegin = middle + 1;
    for(i = begin; begin <= middle && rbegin <= end; i++)
    {
        if(adjuvant[begin] <= adjuvant[rbegin])
        {
            v[i] = adjuvant[begin];
            begin++;
        }else
        {
            v[i] = adjuvant[rbegin++];
        }
    }
    while(rbegin <= end) v[i++] = adjuvant[rbegin++];
    while(begin <= middle) v[i++]  = adjuvant[begin++];
 

    return 0;
}
void Print(int* v, int begin, int end)
{
    printf("\n[Debug]: ");
    for(int i = begin; i < end; i++)
    {
        printf("%d,", v[i]);
    }
    printf("%d\n", v[end]);
}
char mPredicate(int a, int b)
{
    if(a >= b)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int merge_sort(int* v, int begin, int end, int* adjuvant)
{
    if(begin < end)
    {
        int middle = (begin + end) / 2;
        merge_sort(v, begin, middle, adjuvant);
        merge_sort(v, middle + 1, end, adjuvant);

        //printf("before merge:begin %d, middle %d, end %d", begin, middle, end);
        //Print(v, begin, end);
        merge_ordered(adjuvant, v, middle - begin + 1, v + middle + 1 , end - middle, mPredicate);
        for(int i = begin; i <= end; i++)
        {
            v[i] = adjuvant[i - begin];
        }
        //merge(v, begin, middle, end, adjuvant);
        //printf("after merge:");
        //Print(v, begin, end);
    } 
    return 0;
}

int merge_sort(int* v, int begin, int end)      //不能在递归中分配内存,使用C++方式编译就有重载
{
    int* adjuvant = (int*) malloc(sizeof(int) * (end - begin + 1));
    merge_sort(v, begin, end, adjuvant);
    free(adjuvant);    
    return 0;
}

int heap_adjust(int *v, int ipending, int end)
{
    int pend    = v[ipending];
    int max     = ipending;
    //有层次遍历特性，找到左右孩子
    //每次更新的位置为left/right，即是每次至少会将区间减半。所以该算法复杂度为lg(n)
    int left    = ipending<<1;
    int right   = (ipending<<1) + 1;

    if(ipending <= (end >> 1))
    {
        //取left/right/max中的最大值。
        if(left <= end && v[left] > v[max])
        {
            max = left;
        }
        if(right <= end && v[right] > v[max])
        {
            max = right;
        }

        //如果最大值是其子节点，则条件子树。
        if(max != ipending)
        {
            v[ipending] = v[max];
            v[max]      = pend;

            heap_adjust(v, max, end);
        }

        //如果最大节点是它本身，则调整完毕——它的子树本身是满足堆性质的。

    }
    return 0;
}
int heap_sort(int* v, int begin, int end)
{
    int i = 0;

    //建立大顶堆
    for(i = end >> 1; i >= begin; i-- )
    {   //从第一个非叶子节点开始检查性质——叶节点本身满足性质
        heap_adjust(v, i, end);
    }

    int adjuvant = 0;
    for(i = end; i >= begin; i--)
    {
        //每次把排好序的放到数组末尾，把堆的最后一个元素放到跟节点。
        adjuvant    = v[begin];
        v[begin]    = v[i];
        v[i]        = adjuvant;

        heap_adjust(v, begin, i - 1);
    }


    return 0;
}

long long fibonaci(int n)
{
    if(n <= 0)
    {
        return 0;
    }
    if(n <= 2)
    {
        return 1;
    }
    return fibonaci(n - 1) + fibonaci(n - 2);
}

/*
int merge(int*v, int begin, int middle, int end)   
    //这是算法导论上面的，但是这样分配内存效率很低。注意到，每次分配的内存最多是O(n)
{
    int rear    = middle - begin + 1;
    int front   = end - middle;

    int* r      = (int*)malloc(sizeof(int) * rear);
    int* f      = (int*)malloc(sizeof(int) * front);

    int i = 0, j = 0;
    for(i = 0; i < rear; i++)
    {
        r[i] = v[begin + i -1];
    }
    for(j = 0; j < front; j++)
    {
        f[j] = v[middle + j];
    }

    i = 0, j = 0;
    for(int k = begin; k < end; k++)
    {
        if(r[i] <= f[j])
        {
            v[k] = r[i];
            i++;
        }else 
        {
            v[k] = f[j];
            j++;
        }
    }

    free(f);
    free(r);


    return 0;
}
*/

/*
int merge_sort(int* v, int begin, int end)
{
    if(begin < end)
    {
        int middle = (begin + end) / 2;
        merge_sort(v, begin, middle);
        merge_sort(v, middle + 1, end);
        merge(v, begin, middle, end);
    }
    return 0;
}

*/


