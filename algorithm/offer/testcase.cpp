/*************************************************************************
	> File Name: testcase.cpp
	> Author: liulianglu
	> Description: 
	> Created Time: Sun 24 Sep 2017 04:31:29 AM EDT
 ************************************************************************/

#include<stdio.h>
#include<iostream>
using namespace std;
#include"offer.h"

#define end(v) sizeof(v)/sizeof(int) - 1

void print(int* v, int begin, int end)
{
    while(begin<end)
    {
        printf("%d,", v[begin++]);
    }
    printf("%d\n", v[begin]);
}

void test40()
{
    int sequential[]    = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int reverse[]       = {9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0};

    int random[]        = {5, 4, 5, 6, 7, 8, 9, 3, 2, -100, 120};

    const int k     = 5; 
    int out[k]      = {0};

    cout<<"The array:";
    print(sequential, 0, end(sequential));
    get_least_numbers(sequential, 0, end(sequential), out, k);
    cout<<"least "<<k<<endl;
    print(out, 0, k - 1);

    cout<<"The array:";
    print(reverse, 0, end(reverse));
    get_least_numbers(reverse, 0, end(reverse), out, k);
    cout<<"least "<<k<<endl;
    print(out, 0, k - 1);

    cout<<"The array:";
    print(random, 0, end(random));
    get_least_numbers(random, 0, end(random), out, k);
    cout<<"least "<<k<<endl;
    print(out, 0, k - 1);

}

int main(int argc, char *argv[])
{
    test40();
}
