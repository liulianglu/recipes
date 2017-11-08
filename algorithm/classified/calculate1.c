/*************************************************************************
	> File Name: calculate1.c
	> Author: liulianglu
	> Description: 任意输入一个数字，计算出从1-n中包含的1的个数 
	> Created Time: Sat 30 Sep 2017 02:29:14 AM EDT
 ************************************************************************/

#include<stdio.h>



int caclculate1(int n)
{
    int sum = 0;
    int k   = 0, number;    //k 可以不使用，如果写成函数调用，就需要要分配两个变量。
    for(int i = 1; i <= n; i++)
    {
        k = 0;
        number = i;
        while(number > 0)
        {
            k  = number % 10;
            if(k == 1)
            {
                sum++;
            }
            number = number / 10;
        }
    }
    return sum;
}
