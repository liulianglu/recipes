/*************************************************************************
	> File Name: 40.cpp
	> Author: liulianglu
	> Description:从给定的序列中，找出最小（大）的 k 个数
	> Created Time: Sun 24 Sep 2017 03:01:44 AM EDT
 ************************************************************************/

#include"offer.h"

void get_least_numbers(int* data, int begin, int end, int k,
        multiset<int, greater<int> >& result)    //默认使用递增，这里采用递减。
{
    multiset<int, greater<int> >::iterator it = result.begin();
    for(int i = begin; i <= end; i++)
    {
        if(result.size() < k)
        {
            result.insert(data[i]);
        }else
        {
            it = result.begin();    //红黑树已经有序！
            if(data[i] < *it)
            {
                result.erase(it);
                result.insert(data[i]);
            }
        }
    }
}

