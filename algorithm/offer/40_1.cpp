/*************************************************************************
	> File Name: 40_1.cpp
	> Author: liulianglu
	> Description: 
	> Created Time: Sun 24 Sep 2017 04:08:01 AM EDT
 ************************************************************************/

#include<iostream>
using namespace std;

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
/*
 *  最坏情况下：data 有序：O(n*k),逆序：O(n*(n-k))
 *  最好情况下：直接选中了第k大的，一次partion完成O(n)
 *  通常情况下，一次可以移动比较多的，它是根据序列值，不断的向k靠近
 *
 *  特点：
 *  输出的k个数并不是排序的
 *  会导致源序列的数据顺序改变——可以没有output,结果就是它的前k个数。
 *  最坏情况下会达到O(n*n)
 *
 *  如果用冒泡排序的思想——每次选择第几大的数据，时间复杂度就稳定在O(kn)
 */
void get_least_numbers(int* data, int begin, int end,
        int* output, int k)
{
    int stastics = 0;
    int middle = partion(data, begin, end);
    while(middle != k - 1)
    {
        stastics++;
        if(middle > k - 1)
        {
            end = middle - 1;
        }else 
        {
            begin = middle + 1;
        }
        middle = partion(data, begin, end);
    }
    for(middle = 0; middle < k; middle++)
    {
        output[middle] = data[middle];
    }

    cout<<"The while spend: "<<stastics<<endl;
}
