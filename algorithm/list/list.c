/*************************************************************************
	> File Name: list.c
	> Author: liulianglu
	> Description: 
	> Created Time: Tue 26 Sep 2017 05:38:15 AM EDT
 ************************************************************************/

#include<stdlib.h>
#include"list.h"

/*
 *  链表带头结点
 *  由于单链表只有一个指针，所以环一定是尾节点指向前面的应该节点。
 */
ListNode* create_ListNode(int* v, int size)
{
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    if(head)
    {
        head->value = 0;
        head->next  = NULL;

        ListNode* current  = NULL, *it = head;
        for(int i = 0; i < size; i++)
        {
             current = (ListNode*)malloc(sizeof(ListNode));
            if(current)
            {
                current->next   = NULL;
                current->value  = v[i];

                it->next = current;
                it       = current;
            } else 
            {
                destroy_ListNode(&head);
            } 
        }

    }
    return head;
}

/*
 *  创建一个循环链表，返回循环链表的尾指针
 */
ListNode* create_cycle_ListNode(int*v, int size)
{
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    if(head)
    {
        head->value = 0;
        head->next  = NULL;

        ListNode* current  = NULL, *it = head;
        for(int i = 0; i < size; i++)
        {
            current = (ListNode*)malloc(sizeof(ListNode));
            if(current)
            {
                current->next   = NULL;
                current->value  = v[i];

                it->next = current;
                it       = current;
            } else 
            {   //没有创建好就还是一个普通的单链表！
                destroy_ListNode(&head);
            } 
        }

        it->next = head;    //如果链表为空，则头结点指向头结点。
        return it;

    }
    return head;        //连头结点也没有，那就是空。

}

/*
 *  创建一个单链表，单链表中带环。
 *  环的位置是第pos个位置。
 *  本来可以在创建链表的时候，记录下第pos个指针，直接用尾指针指过来。
 *  此处为了复用循环链表，所以遍历了两次。
 */
ListNode* create_ListNode_cycle(int*v, int size, int pos)
{
    ListNode* list = create_cycle_ListNode(v, size);
    if(list)
    {
        ListNode* it    = list->next;
        ListNode* head  = list->next;
        while(it != list && pos--) //不可能有空指针了！pos过大会环回。
        {
            it = it->next;
        }

        list->next = it;        //不算头节点。第0个为头节点。
        return head;
    }

    return NULL;
}

void destroy_ListNode(ListNode** head)
{
    ListNode* it        = *head;
    ListNode* current   = it;
    while(it)
    {
        current = it;
        it      = it->next;

        free(current);
        current = NULL;
    }
}

ListNode* getMiddle(ListNode* head)
{
    if(head)
    {
        //head = head->next;      //去掉头节点。
        ListNode* fast  = head->next;
        ListNode* slow  = head->next;

        while(fast->next)
        {
            //slow = slow->next;    先后移了，如果是偶数前半部就会多一个。
            fast = fast->next;

            if(fast->next)
            {
                slow = slow->next;  //后后移，如果是偶数个前半部会少一个。
                fast = fast->next;
            }
        }
        return slow;
    }
    return head;
    
}

char isCycle(ListNode* head)
{
    ListNode* fast = head;
    while(head)
    {
        fast = fast->next;
        if(fast)
        {
            if(fast == head)
            {
                return 1;
            }else 
            {
                fast = fast->next;
                head = head ->next;
            }
        }
    }

    return 0;
}
