/*************************************************************************
	> File Name: circulation.c
	> Author: liulianglu
	> Description: 一些经典算法的循环实现方式
        所有类型都采用int，以代替模版的可扩展性 
        函数命名使用下划线代替大写字母
	> Created Time: Thu 21 Sep 2017 11:22:25 PM EDT
 ************************************************************************/

#include"algorithm.h"
#include"merge_ordered.h"

#include<stdio.h>
#include<stdlib.h>

#include<stack>
using namespace std;

int binary_search(int* des, int begin, int end, int key)
{
    int middle = -1;
    while(begin <= end)
    {
        middle = (begin + end) / 2;
        if(key == des[middle])
        {
            return middle;
        }else if(key < des[middle])
        {
            end = middle -1;
        }else
        {
            begin = middle + 1;
        }
    }
    return -1;

}

int partion(int* v, int begin, int end)
{
    int privot = v[begin];
    while(begin < end)
    {
        while(begin < end && privot < v[end]) end--;
        if(begin < end)
        {
            v[begin++] = v[end];
        }
        while(begin < end && privot > v[begin]) begin++;
        if(begin < end)
        {
            v[end--] = v[begin];
        }

    } //循环退出的唯一条件是begin == end——如果进入过。

    v[begin] = privot;

    return begin;
}

int quick_sort(int* v, int begin, int end)
{
    if(begin < end)
    {
        int middle = 0; 
        stack<int> lStack;

        lStack.push(begin);
        lStack.push(end); 

        while(!lStack.empty())      //用栈模仿递归！ ——很多时候要相信自己！
        {
            end     = lStack.top();
            lStack.pop();
            begin   = lStack.top();
            lStack.pop();
            middle  = partion(v, begin, end);
            if(middle < end - 1)
            {
                lStack.push(middle + 1);
                lStack.push(end);
            }

            if(middle > begin + 1)
            {
                lStack.push(begin);
                lStack.push(middle - 1);
            }

        }
    }

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

int merge_sort(int* v, int begin, int end)
{
    if(begin < end)     //利用的是一个元素本来就有序.
    {
        int step    = 1;
        int size    = end - begin + 1;
        int entire  = 0;
        int offset  = 0;
        int i       = 0;
        int*adjuvant= (int*)malloc(sizeof(int) * size);
        while(step <= size)
        {
            offset = step + step;
            entire = size - offset;
            for(i = 0; i <= entire; i += offset)//0到offset有序
            {
                //printf("before merge:begin %d, middle %d, end %d", begin, middle, end);
                //Print(v, begin, end);
                merge(v, i, i + step - 1, i + offset - 1, adjuvant);
                //printf("after merge:");
                //Print(v, begin, end);
            }
            if(i + step < size) //最后一个不完整的划分，如果超过了中点折需要合并
            //比如step =2, offset = 4
            //划分9、10个长度其本身有序，可以跳过此步骤；
            //但是如果划分的是11个长度的序列这要执行。1 2 3 4 5 6 7  8 9 10 11 
            //与循环中的条件的区别是：此时size < i + offset
            {
                merge(v, i, i + step - 1, size - 1, adjuvant);
            }
            
            step <<= 1;
        }
    } 

    return 0;
}

int heap_adjust(int* v, int begin, int end)
{
    int pend    = v[begin];                 //先保存待插入值，找到插入位置begin之后再放入。
    int i       = 0;
    for(i = begin << 1; i <= end; i = i << 1)    //从根节点开始，依次调整最大的子树。
    {
        if(i < end && v[i] <= v[i + 1])     //选出大的子树
        {
            i++;
        }
        if(v[i] <= pend)                    //如果跟节点是最大的，则已经满足特性。
        {
            break;
        }
        v[begin] = v[i];                   //将大的子节点放到根节点上。
        begin = i;                         //begin始终指向插入位置。
    }
    v[begin] = pend;
    return 0;
}
int heap_sort(int* v, int begin, int end)
{
    if(v && begin < end)
    {
        //int len = end - begin + 1;
        int i;
        int temp = 0;
        for(i = end >> 1; i >= begin; i--) //v是存储的层次遍历，这里表示的是从第一个非叶子节点开始。
        {
            //Print(v, i, end);
            heap_adjust(v, i, end);
        }

        for(i = end; i > begin; i--)
        {
            temp = v[begin];
            v[begin] = v[i];
            v[i] = temp;

            heap_adjust(v, begin, i - 1);
        }
    }
    return 0;
}

long long  fibonaci(int n)
{
    if(n <= 0)
    {
        return 0;
    }else if(n <= 2)
    {
        return 1;
    }else 
    {
        int result = 0;

        int current = 1;
        int last = 1;

        for(int i = 2; i < n; i++)  //从第3个数字开始计算
        {
            result  = current + last;
            last    = current;
            current = result;

        }

        return result;
    }
}
