/*************************************************************************
	> File Name: test_binary_tree.c
	> Author: liulianglu
	> Description: the test unit of the binary tree 
	> Created Time: Fri 22 Sep 2017 05:21:40 AM EDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#include"binary_tree.h"

#define end(v) sizeof(v)/sizeof(int) - 1

binary_tree* create_node(int v)
{
    binary_tree* node = (binary_tree*)malloc(sizeof(binary_tree));

    node->value     = v;
    node->left      = NULL;
    node->right     = NULL;
    node->prarent   = NULL;

    return node;
}

void transplante(binary_tree* root, binary_tree* node)
{

}

char insert_binary_tree(binary_tree* *root, binary_tree* node)
{
    if(!*root)
    {
        *root = node;
        return 1;
    }
    if(!node)
    {
        return 1;
    }

    binary_tree* it = *root;
    binary_tree* before = it;
    while(it)
    {
        before = it;
        if(it->value >= node->value)
        {
            it = it->left;
        }else 
        {
            it = it->right;
        }
    }

    if(before->value >= node->value)
    {
        before->left = node;
    }else
    {
        before->right = node;
    }

    return 1;
}

//想了一下，构造二叉树还是二叉排序树最好构造。
binary_tree* create_binary_sort_tree(int* src, int begin, int end)
{
    if(begin <= end && src)
    {
        binary_tree* root = (binary_tree*)malloc(sizeof(binary_tree));
        root->value     = src[begin++];

        binary_tree* current = NULL;    //以当前节点来看，基本上就是一个死循环了！：
        while(begin <= end)
        {
            current = create_node(src[begin++]);
            insert_binary_tree(&root, current);
        }

        return root;
    }

    return NULL;
}

/*
void visit(binary_tree* node)
{
    printf("%d,", node->value);
}
*/
int main(int argc, char *argv[])
{

    int base1[] = {6, 5, 6, 7, 8, 3, 9, 2, 10, -11, 100};

    binary_tree* pTree = create_binary_sort_tree(base1, 0, end(base1));

    pre_order(pTree);

    printf("\n");

    middle_order(pTree);        //输出排序序列!
    printf("\n");

    post_order(pTree);
    printf("\n");

    return 0;


}
