/*************************************************************************
	> File Name: offer.h
	> Author: liulianglu
	> Description: 
	> Created Time: Sun 24 Sep 2017 04:26:50 AM EDT
 ************************************************************************/

#ifndef _OFFER_H
#define _OFFER_H
#include<set>

using namespace std;

void get_least_numbers(int*v, int begin, int end,
        int *output, int k);
void get_least_numbers(int*v, int begin, int end,
        int k, multiset<int, greater<int> >& result);

#endif
