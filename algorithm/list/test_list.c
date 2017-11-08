/*************************************************************************
	> File Name: test_list.c
	> Author: liulianglu
	> Description: 
	> Created Time: Tue 26 Sep 2017 09:33:14 PM EDT
 ************************************************************************/

#include<stdio.h>
#include"list.h"

#define num(v) sizeof(v)/sizeof(int)

void print(ListNode* list)
{
    printf("\noutput the list: \n");
    if(list)
    {
        list = list->next;
    }
    while(list)
    {
        printf("%d,", list->value);
        list = list->next;
    }
    printf("\n");
  
}

int main(int argc, char *argv[])
{
    int test1[] = {1,2,3,4,5,6,7,8,9};
    int test2[] = {9,8,7,6,5,4,3,2};

    ListNode* list = create_ListNode(test1, num(test1));

    ListNode* middle = getMiddle(list);
    print(list);
    printf("middle: %d\n", middle->value);

    destroy_ListNode(&list);

    list    = create_ListNode(test2, num(test2));
    middle  = getMiddle(list);
    print(list);
    printf("middle: %d\n", middle->value);
    destroy_ListNode(&list);

    list    = create_ListNode_cycle(test1, num(test1), 5);
    if(isCycle(list))
    {
        printf("Judge whether the ListNode has a loops correct!\n");
    }else 
    {
        printf("Judge cycle error!\n");
    }


    return 0;
}
