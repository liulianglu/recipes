/*************************************************************************
	> File Name: rb_tree.h
	> Author: liulianglu
	> Description: 
	> Created Time: Sun 24 Sep 2017 09:23:42 AM EDT
 ************************************************************************/

#ifndef _RB_TREE_H
#define _RB_TREE_H

#define RED     1
#define BLACK  0

typedef struct rbtree_node
{

    int                   key;  
    //unsigned int        key;               
    struct rbtree_node* left;
    struct rbtree_node*     right;
    struct rbtree_node*     parent;
    char                color;
    char                data[3];

    void red()  { this->color = RED; }
    void black(){ this->color = BLACK; }

    char isRed() { return this->color == RED; }
    char isBlack(){ return this->color == BLACK; }



}rbtree_node;

typedef void (*rbtree_insert_pt) (rbtree_node* root, 
        rbtree_node* node, rbtree_node* sentinel);


typedef struct rbtree
{
    rbtree_node*        root;
    rbtree_node*        sentinel;
    rbtree_insert_pt    insert;
    
    rbtree_node* minimum(rbtree_node* x)
    {
        while(x->left)  x = x->left;
        return x;
    }

    rbtree_node* maximum(rbtree_node* x)
    {
        while(x->right) x = x->right;
        return x;
    }

}rbtree;

rbtree_node* create_rbtree_node(rbtree*,int key);   //分配并初始化一个节点。
rbtree* create_rbtree(int *szkey, int size);    //由数组创建红黑树

char  pre_order(rbtree* T, char (*visit) (rbtree_node*));       //使用先序和中序，可以手动画出二叉树，而不用去调试找BUG
char  middle_order(rbtree* T, char (*visit)(rbtree_node* node));    //中序遍历红黑树——按序输出

char destroy_rbtree_node(rbtree* T, rbtree_node* node);     //删除树中所有节点
char post_order(rbtree* T, char (visit)(rbtree* T, rbtree_node* node));       //后序访问红黑树——依次删除红黑树节点:先序、中序都不满足。

//后序遍历，计算树的高度。这里只是为了说明原理，可以合并在一起写。
inline int calculate_height(int lheight, int rheight)
{
    return lheight > rheight ? ++lheight: ++rheight;
}
int post_order(rbtree* T, int(visit) (int, int));

void destroy_rbtree(rbtree** T);                            //删除整棵树

inline char rbtree_isNull(rbtree *T)
{
    return T ? T->root == T->sentinel : 1;
    /*
    if(T)
    {
        return T->root == T->sentinel ? 1 : 0;
    }
    return 1;
    */
}
void rbtree_insert(rbtree* T, rbtree_node* node);
void rbtree_delete(rbtree* T, rbtree_node* node);
rbtree_node* rbtree_find(rbtree* T ,int key);


#endif
