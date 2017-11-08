/*************************************************************************
	> File Name: test.c
	> Author: liulianglu
	> Description: 
	> Created Time: Fri 22 Sep 2017 01:02:15 AM EDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"algorithm.h"
#include"merge_ordered.h"

#define end(v)  sizeof(v)/sizeof(int) -1
#define num(v)  sizeof(v)/sizeof(int)
#define Num(v)  end(v)

void test_binary_search()
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
        


    printf("testcase1: %d\n", binary_search(testcase[0], 0, 9, key));
    printf("testcase2: %d\n", binary_search(testcase[1], 0, 8, key));
    printf("testcase3: %d\n", binary_search(testcase[2], 0, 9, key));
    printf("testcase4: %d\n", binary_search(testcase[3], 0, sizeof(base4)/sizeof(int) - 1, key));

}

void print(int* v, int begin, int end)
{
    while(begin < end)
    {
        printf("%d,", v[begin++]);
    }
    if(begin == end)
    {
        printf("%d\n", v[begin]);
    }
}

char predicate(int front, int rear)
{
    if(front <= rear)
    {
        return 1;
    }else
    {
        return 0;
    }
}
void call_sort(int*v, int begin, int end, char key)
{
    printf("\nbefore sort, the array:\n");
    print(v, begin, end);
    printf("after ");

    switch(key)
    {  
        case 'S':
        case 's':
            printf("merge_ordered first, sort\n");
            //merge_ordered()
            //printf("not support");
        case 'Q':
        case 'q':
            printf("quick ");
            quick_sort(v, begin, end);
            break;
        case 'M':
        case 'm':
            printf("merge ");
            merge_sort(v, begin, end);
            break;
        case 'H':
        case 'h':
            printf("heap ");
            heap_sort(v, begin, end);
            break;
      
        default:
            break;
    }

    printf("sort, the result:\n");
    print(v, begin, end);
}

void test_sort(char key)
{
    int testcase1[] = {-1, 0, 1, 3, 6, 100000};
    int testcase2[] = {1000, 56, 34, 0, -2, -6, -100000};

    int testcase3[] = {6, 5, 4, 3, 2, 2, 1, 3, 7, 8, 10, 100};

    call_sort(testcase1, 0, Num(testcase1), key);
    call_sort(testcase2, 0, Num(testcase2), key);
    call_sort(testcase3, 0, Num(testcase3), key);

    if(key == 's' || key == 'S')
    {
        int* des = (int*)malloc(sizeof(int) * (num(testcase1) + num(testcase2)));
        printf("\nbefore merge:");
        print(testcase1, 0, end(testcase1));
        print(testcase2, 0, end(testcase2));

        merge_ordered(des, testcase1, num(testcase1), 
                testcase2, num(testcase2),
                predicate);
        print(des, 0, num(testcase1) + num(testcase2) - 1);

    }
    else
    {
       
    }

}
void test_quick_sort()
{
    printf("***** test_quick_sort **********\n");

    //const int testcaseNum = 4;
    //int* testcase[testcaseNum];
    //int nDes    = 10;

    //testcase[0] = (int*)malloc(sizeof(int) * nDes);
    int testcase1[] = {-1, 0, 1, 3, 6, 100000};
    int testcase2[] = {1000, 56, 34, 0, -2, -6, -100000};

    int testcase3[] = {6, 5, 4, 3, 2, 2, 1, 3, 7, 8, 10, 100};

    printf("testcase1: ");
    print(testcase1, 0, Num(testcase1));
    quick_sort(testcase1, 0, Num(testcase1));
    print(testcase1, 0, Num(testcase1));

    printf("testcase2: ");
    print(testcase2, 0, Num(testcase2));
    quick_sort(testcase2, 0, Num(testcase2));
    print(testcase2, 0, Num(testcase2));

    printf("testcase3: ");
    print(testcase3, 0, Num(testcase3));
    quick_sort(testcase3, 0, Num(testcase3));
    print(testcase3, 0, Num(testcase3));
}


int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Execute the default: binary_search\n");
        test_binary_search();
    }else if(0 == strcasecmp(argv[1], "-h")|| 0 == strcasecmp(argv[1], "-help"))
    {
        printf("test binary search  ---------------     binary_search   \n");
        printf("test quick  sort    ---------------     quick_sort      \n");
        printf("test merge  sort    ---------------     merge_sort      \n");
        printf("test heap   sort    ---------------     heap_sort       \n");
        printf("test merge  ordered ---------------     merge_ordered   \n");

    }
    else if(strcmp(argv[1], "binary_search") == 0)
    {
        test_binary_search();
    }else if(0 == strcmp(argv[1], "quick_sort"))
    {
        //test_quick_sort();
        test_sort('q');
    }else if(0 == strcmp(argv[1], "merge_sort"))
    {
        test_sort('m');
    }else if(0 == strcmp(argv[1], "heap_sort"))
    {
        test_sort('h');
    }else if(0 == strcmp(argv[1], "merge_ordered"))
    {
        test_sort('s');
    }else if(0 == strcmp(argv[1], "fib"))
    {
        printf("The result of 10 is :%lld \n",fibonaci(atoi(argv[2])));
    }
    else 
    {
        printf("The command not found!\n");
    }
    return 0;
}
