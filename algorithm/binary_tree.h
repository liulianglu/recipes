/*************************************************************************
	> File Name: binary_tree.h
	> Author: liulianglu
	> Description: 
	> Created Time: Fri 22 Sep 2017 05:05:17 AM EDT
 ************************************************************************/

#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

typedef struct binary_tree
{

    //void* value;
    int value;
    struct binary_tree* left;
    struct binary_tree* right;

    struct binary_tree* prarent;   //没有此变量，如何找到后继？
}binary_tree;

void visit(binary_tree* node);
binary_tree* pre_order(binary_tree* t);
binary_tree* middle_order(binary_tree* t);
binary_tree* post_order(binary_tree* t);

binary_tree* precursor(binary_tree* t);
binary_tree* succeed(binary_tree* t);

#endif
