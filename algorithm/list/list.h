/*************************************************************************
	> File Name: list.h
	> Author: liulianglu
	> Description: 
	> Created Time: Sun 24 Sep 2017 09:10:54 AM EDT
 ************************************************************************/

#ifndef _LIST_H
#define _LIST_H

typedef struct ListNode
{
    int                 value;
    struct ListNode*    next;
}ListNode;

ListNode* create_ListNode(int* data, int size);
void destroy_ListNode(ListNode**);

ListNode* getMiddle(ListNode*);

ListNode* create_ListNode_cycle(int* data, int size, int pos);
char isCycle(ListNode*);

#endif
