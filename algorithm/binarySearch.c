/*************************************************************************
	> File Name: binarySearch.c
	> Author: liulianglu
	> Description: 
	> Created Time: Mon 18 Sep 2017 05:57:51 AM EDT
 ************************************************************************/

#include<stdio.h>

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
int binarySearch(int* src,int begin,  int end, int des)
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
         return binarySearch(src, begin, middle -1, des);

    }else 
    {
        return binarySearch(src, middle + 1, end, des);
    }
}


int main(int argc, char *argv[])
{
    //0.查找值大于最大值
    //1.查找值小于最小值
    //2.奇数个序列成功
    //3.查找偶数个序列成功
    //4.查找失败
    
    const int testcaseNum   = 4;
    const int key           = 10;

    /*
    int testcase[][10] = {              //二维数组可以省略的是行，而不是列
        {0,1,2,3,4,5,6,7,8,9},              //序列为偶数
        {11,12,13,14,15,16,17,18,19},
        {8,9,10,11,12,13,14,15,16,17,18},
        {10,11,12,13,14,15,16,17,18}

    };
    */

    int* testcase[testcaseNum];

    //锯齿形数组只能是操作地址：只能使用已经分配好的。
    //开始想着这样可以方便计算长度，
    //int型是不能使用strlen来计算的,sizeof只能用在原数组上。
    
    int base1[] = {0,1,2,3,4,5,6,7,8,9};              //序列为偶数
    int base2[] = {11,12,13,14,15,16,17,18,19};
    int base3[] = {8,9,10,11,12,13,14,15,16,17,18};
    int base4[] = {10,11,12,13,14,15,16,17,18};
    testcase[0] = base1;
    testcase[1] = base2;
    testcase[2] = base3;
    testcase[3] = base4;
        


    printf("testcase1: %d\n", binarySearch(testcase[0], 0, 9, key));
    printf("testcase2: %d\n", binarySearch(testcase[1], 0, 8, key));
    printf("testcase3: %d\n", binarySearch(testcase[2], 0, 9, key));
    printf("testcase4: %d\n", binarySearch(testcase[3], 0, sizeof(base4) - 1, key));

    return 0;
}
