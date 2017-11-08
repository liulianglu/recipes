/*************************************************************************
	> File Name: binary_tree_circulation.cpp
	> Author: liulianglu
	> Description: The circulatory algorithm of the binary tree.
	> Created Time: Sat 23 Sep 2017 10:34:45 AM EDT
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

#include"binary_tree.h"

void visit(binary_tree* node)
{
    cout<<node->value<<",";
}

binary_tree* pre_order(binary_tree* r)
{
    stack<binary_tree*> assistant;
    binary_tree* node               = NULL;
    assistant.push(r);
    while(!assistant.empty())
    {
        node = assistant.top();
        assistant.pop();
        visit(node);
        if(node->right)
        {//栈决定先右孩子
            assistant.push(node->right);
        }
        if(node->left)
        {
            assistant.push(node->left);
        }

    }
    return r;
}
binary_tree* middle_order(binary_tree* r)
{
    stack<binary_tree*> assistant;
    binary_tree* node = NULL;
    assistant.push(r);
    while(!assistant.empty())
    {
        while(NULL != (node = assistant.top())) 
        {
            //assistant.pop();
            assistant.push(node->left);
        }
        assistant.pop();    //最后一个是空指针，删除。
        if(!assistant.empty())
        {
            node = assistant.top();
            assistant.pop();
            visit(node);
            assistant.push(node->right);
        }
    }
    return r;
}

binary_tree* post_order(binary_tree* r)
{
    stack<binary_tree*> assistant;
    binary_tree* node   = NULL;
    binary_tree* pre    = NULL;
    assistant.push(r);
    while(!assistant.empty())
    {
        node = assistant.top();
        if((NULL == node->left && NULL == node->right) ||
                (pre && (node->left == pre || node->right == pre)))
        {
            visit(node);
            assistant.pop();
            pre = node;
        }else
        {
            if(node->right)
            {//栈决定先右孩子
                assistant.push(node->right);
            }
            if(node->left)
            {
                assistant.push(node->left);
            }
        }
    }
    return r;
}
