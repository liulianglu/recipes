/*************************************************************************
	> File Name: binary_tree_recursion.cpp
	> Author: liulianglu
	> Description: 
	> Created Time: Fri 22 Sep 2017 07:26:43 AM EDT
 ************************************************************************/

#include<iostream>
#include"binary_tree.h"

using namespace std;

void visit(binary_tree* t)
{
    cout<<t->value<<",";
}

binary_tree* pre_order(binary_tree* t)
{
    if(!t)
    {
        return t;
    }    
    visit(t);
    if(t->left)
    {
        pre_order(t->left);
    }

    if(t->right)
    {
        pre_order(t->right);
    }

    return t;
}

binary_tree* middle_order(binary_tree* t)
{
    if(!t)
    {
        return t;
    }

    if(t->left)
    {
        middle_order(t->left);
    }
    visit(t);
    if(t->right)
    {
        middle_order(t->right);
    }

    return t;
}

binary_tree* post_order(binary_tree* t)
{
    if(!t)
    {
        return t;
    }

    if(t->left)
    {
        post_order(t->left);
    }
    if(t->right)
    {
        post_order(t->right);
    }

    visit(t);

    return t;
}
