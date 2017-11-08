/*************************************************************************
	> File Name: binary_tree.c
	> Author: liulianglu
	> Description: the algorithms of the binary tree 
	> Created Time: Fri 22 Sep 2017 05:07:57 AM EDT
 ************************************************************************/


#include"binary_tree.h"

binary_tree* middle_precursor(binary_tree* t)
{
    if(t->left)
    {
        return t->left;
    }else 
    {
        return t->prarent;
    }
}




