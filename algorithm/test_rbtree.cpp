/*************************************************************************
	> File Name: test_rbtree.cpp
	> Author: liulianglu
	> Description: 
	> Created Time: Mon 25 Sep 2017 09:24:43 PM EDT
 ************************************************************************/

#include"rb_tree.h"

#include<iostream>
using namespace std;
#define num(v) sizeof(v)/sizeof(int)
char print(rbtree_node* node)
{
    cout<<node->key<<",";
    return 1;
}

void rbtree_info(rbtree* T)
{
    cout<<"\nThe pre_order of the rbtree is :\n";
    pre_order(T, print);
    cout<<"\nThe middle_order of the rbtree is :\n";
    middle_order(T, print);
    cout<<"\nheight: "<<post_order(T, calculate_height)<<endl;
}

void test_info(int *v, int size)
{
    cout<<"The test array is:";
    for(int i = 0; i < size; i++)
    {
        cout<<v[i]<<",";
    }
    cout<<" size: "<<size<<endl;
}

void base_function()
{
    //递增序列
    int testcase1[] = {1,2,3,4,5,6,6,7,8};
    rbtree* pTree = create_rbtree(testcase1, num(testcase1));

    test_info(testcase1, num(testcase1));
    rbtree_info(pTree);

    //插入一个最大值
    cout<<"After insert a max(100):";
    rbtree_node* node = create_rbtree_node(pTree,100);
    rbtree_insert(pTree, node);
    rbtree_info(pTree);

    node = create_rbtree_node(pTree, -1000);
    rbtree_insert(pTree, node);
    rbtree_info(pTree);

    node = create_rbtree_node(pTree, 20);
    rbtree_insert(pTree, node);
    rbtree_info(pTree);

    cout<<"After delete key -1000, The tree is :"<<endl;    //最左
    node = rbtree_find(pTree, -1000);
    rbtree_delete(pTree, node);
    rbtree_info(pTree);

    cout<<"After delete key 100, The tree is :"<<endl;      //最右
    node = rbtree_find(pTree, 100);

    rbtree_delete(pTree, node);
    rbtree_info(pTree);
    cout<<"After delete key 5, The tree is :"<<endl;      //随机
    node = rbtree_find(pTree, 5);
    rbtree_delete(pTree, node);
    rbtree_info(pTree);

}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        base_function();   
    }
    /*
    int testcase1[] = {1,2,3,4,5,6,6,7,8};

    rbtree* pTree = create_rbtree(testcase1, num(testcase1));

    pre_order(pTree, print);
    cout<<endl;
    middle_order(pTree, print);
    cout<<endl;

   
    rbtree_node* node = create_rbtree_node(pTree,100);
    rbtree_insert(pTree, node);
    middle_order(pTree, print);
    cout<<endl;

    node = create_rbtree_node(pTree, 20);
    rbtree_insert(pTree, node);
    middle_order(pTree, print);
    cout<<endl;

    node = create_rbtree_node(pTree, -1000);
    rbtree_insert(pTree, node);
    middle_order(pTree, print);
    cout<<endl;

    cout<<"After delete key -1000, The tree is :"<<endl;    //最左
    node = rbtree_find(pTree, -1000);
    rbtree_delete(pTree, node);
    middle_order(pTree, print);
    cout<<endl;

    cout<<"After delete key 100, The tree is :"<<endl;      //最右
    node = rbtree_find(pTree, 100);
    rbtree_delete(pTree, node);
    middle_order(pTree, print);
    cout<<endl;

    cout<<"After delete key 5, The tree is :"<<endl;      //随机
    node = rbtree_find(pTree, 5);
    rbtree_delete(pTree, node);
    middle_order(pTree, print);

    cout<<"The height of the tree is :"<<post_order(pTree, calculate_height)<<endl;

    cout<<endl;   

    post_order(pTree, destroy_rbtree_node);
    */

    return 0;
}
