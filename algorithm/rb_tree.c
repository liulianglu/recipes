/*************************************************************************
  > File Name: rb_tree.c
  > Author: liulianglu
  > Description: 
  > Created Time: Sun 24 Sep 2017 10:02:51 AM EDT
 ************************************************************************/

#include"rb_tree.h"
#include<stdlib.h>

rbtree_node* create_rbtree_node(rbtree* T, int key)
{
    rbtree_node* node   = (rbtree_node*)malloc(sizeof(rbtree_node));
    if(node)
    {
        //memset(node, 0, sizeof(rbtree_node));

        node->key   = key;
        node->left  = T->sentinel; //sentinel本身也指向自己，表示结束。
        node->right = T->sentinel;
        node->parent= NULL;     //父节点肯定会被初始化
        node->red();
    }
    return node;
}

char destroy_rbtree_node(rbtree* T, rbtree_node* node)
{
    if(node)
    {
        if(node == T->root)
        {
            T->root = T->sentinel;
        }else if(node == node->parent->left)
        {
            node->parent->left = T->sentinel;
        }else
        {
            node->parent->right = T->sentinel;
        }

        free(node);
        node = T->sentinel;
    }

    return 0;
}
char middle_order(rbtree* T, rbtree_node* node, 
        char (*visit)(rbtree_node*))
{//空值拿到开始判断好像是要好一点，对比自己写的binay_tree_recursion.c
    if(node != T->sentinel)
    {

        if(middle_order(T, node->left, visit))
        {
            if(visit(node))
            {
                if(middle_order(T, node->right, visit))
                {
                    return 1;
                }
            }
        }

        return 0;
    }else
    {
        return 1;
    }
}

char pre_order(rbtree* T, rbtree_node* node, char (*visit)(rbtree_node*))
{
    if(T->sentinel != node)
    {
        if(visit(node))
        {
            if(pre_order(T, node->left, visit))
            {
                if(pre_order(T, node->right, visit))
                {
                    return 1;
                }
            }
        }

        return 0;
    }

    return 1;
}

char pre_order(rbtree*T, char (*visit)(rbtree_node*))
{
    return pre_order(T, T->root, visit);
}

char middle_order(rbtree* T, char (*visit)(rbtree_node*))
{
    return middle_order(T, T->root, visit);
}

char post_order(rbtree* T, rbtree_node* node, 
        char (*visit)(rbtree*, rbtree_node*))
{
    if(node != T->sentinel)
    {
        if(post_order(T, node->left, visit))
        {
            if(post_order(T, node->right, visit))
            {
                if(visit(T, node))
                {
                    return 0;
                }
            }
        }
        return 1;
    }else
    {
        return 0;
    }
}

char post_order(rbtree* T, char (*visit)(rbtree*, rbtree_node*))
{
    return post_order(T, T->root, visit);
}

rbtree* create_rbtree(int* szkey, int size)
{
    int i = 0;
    rbtree* pTree       = (rbtree*)malloc(sizeof(rbtree));
    if(pTree)
    {
        pTree->sentinel     = create_rbtree_node(pTree, -1);
        pTree->root         = pTree->sentinel;
        pTree->insert       = NULL; //
        if(!pTree->sentinel)
        {
            free(pTree);
            pTree = NULL;
        }
    }

    rbtree_node* node   = NULL;
    if(pTree && pTree->sentinel)
    {
        pTree->sentinel->black();
        for(i = 0; i < size; i++)
        {
            node = create_rbtree_node(pTree, szkey[i]);
            if(node)
            {
                rbtree_insert(pTree, node);
            }else 
            {
                //释放已经分配的树。
                destroy_rbtree(&pTree);
            }
        }
    }


    return pTree;
}

char create_rbtree(rbtree** T, int* szkey, int size)
{
    if(*T)
    {
        rbtree_node* node = NULL;
        for(int i = 0; i < size; i++)
        {
            node = create_rbtree_node(*T, szkey[i]);
            if(node)
            {
                rbtree_insert(*T, node);
            }else
            {
                post_order(*T, destroy_rbtree_node);
            }
        }
    }else 
    {
        *T = create_rbtree(szkey, size);
        if(*T)
        {
            return 0;
        }
    }

    return 1;
}
void destroy_rbtree(rbtree** T)
{
    if(*T)
    {
        post_order(*T, destroy_rbtree_node);

        destroy_rbtree_node(*T, (*T)->sentinel);

        free(*T);
        *T = NULL;
    }
}

/*  
 *          x                           y
 *         / \          左旋           / \
 *        1   y         ——>           x   3
 *           / \                     / \
 *          2   3                   1   2
 *  注意rbtree修改左右指针时都要修改父指针。
 * 从上图可以看出，左旋转之后，1的深度+1；2保持不变；3的深度-1；右旋相反。
 * */
void rbtree_left_rotate(rbtree* T, rbtree_node* x)
{
    if(x != T->sentinel)
    {
        rbtree_node* y = x->right;

        x->right = y->left;
        if(y->left != T->sentinel)
        {
            y->left->parent = x;
        }

        y->parent = x->parent;
        if(x == T->root)
        {
            T->root = y;
        }else if(x == x->parent->left)
        {
            x->parent->left = y;
        }else
        {
            x->parent->right = y;
        }

        x->parent = y;
        y->left = x;
    } 
}

void rbtree_right_rotate(rbtree* T, rbtree_node* y)
{
    if(y != T->sentinel)
    {
        rbtree_node* x = y->left;

        y->left = x->right;
        if(x->right != T->sentinel)
        {
            x->right->parent = y;
        }


        x->parent = y->parent;
        if(y == T->root)
        {
            T->root = x;
        }
        else if(y->parent->left == y)
        {
            y->parent->left = x;
        }else         {
            y->parent->right = x;
        }

       
        y->parent = x;
        x->right = y;

    }
}

void rbtree_insert(rbtree* T, rbtree_node* node)
{
    rbtree_node* y = T->sentinel, *x = T->root;
    /*
    if(T->root == T->sentinel)  //空树
    {
        node->parent = NULL;
        node->black();
        T->root = node;
        return ;
    }
    */
    while(x != T->sentinel)     //像排序树一样插入
    {
        y = x;
        x = node->key < x->key ? x->left : x->right;
    }

    //指针初始化
    node->parent = y;
    
    if(y == T->sentinel)
    {
        T->root = node;
    }else if(node->key < y->key)
    {
        y->left = node;
    }else 
    {
        y->right = node;
    }

    node->left  = T->sentinel;
    node->right = T->sentinel;
    

    //先将节点着红色。
    node->red();

    //re-balance the tree
    rbtree_node* uncle = NULL;
    while(node != T->root && node->parent->isRed())    
        //当node不是根节点，其node的父亲是红色节点才需要调整
    {   //进入循环后，y一定为红色；为了清晰，下面直接使用node->parent
        //----------把node->parent写成了y，这个问题定位了好久,要以算法导论中证明的思维来看循环，特别是指针比较多的时候_
        //从而node->parent->parent一定为黑色

        if(node->parent == node->parent->parent->left)
        {
            uncle = node->parent->parent->right;
            if(uncle->isRed())
            {
                node->parent->black();
                uncle->black();
                uncle->parent->red();

                node = uncle->parent;   //每次移动了两层。
            }else   //开始还没有理解为什么这里可以是黑色：
                //node->parent为红色，但是它可能含有子孩子。
                //红黑树的定义中是定义的叶子节点到根节点黑节点相等。
                //所以这种情况就是node->parent的子树和uncle的黑高一样
            {
                //如果node==node->parent-left直接可以很好解决。
                if(node == node->parent->right)
                {
                    node = node->parent;
                    rbtree_left_rotate(T, node);
                }
                node->parent->black();
                node->parent->parent->red();
                rbtree_right_rotate(T, node->parent->parent);
            }
        }else 
        {//与if中对称
            uncle = node->parent->parent->left;
            if(uncle->isRed())
            {
                uncle->black();
                node->parent->black();
                uncle->parent->red();

                node = uncle->parent;
            }else 
            {
                if(node == node->parent->left)
                {
                    node = node->parent;
                    rbtree_right_rotate(T, node);
                }

                node->parent->black();
                node->parent->parent->red();
                rbtree_left_rotate(T, node->parent->parent);
            }
        }
    }

    T->root->black();

}

void rbtree_delete(rbtree* T, rbtree_node* node)
{
    rbtree_node* x, *substitute;

    /* a ordered tree delete */
    //如果只有一个孩子，直接用子孩子替换删除节点。
    if(node->left == T->sentinel)
    {
        x           = node->right;
        substitute  = node;
    }else if(node->right == T->sentinel)
    {
        x           = node->left;
        substitute  = node;
    }else 
    {
        substitute  = T->minimum(node->right);   //可以使用右节点的最小值或者左节点的最大值来替换。
        x           = substitute->right;
    }

    if(substitute == T->root)
    {
        T->root = x;
        x->black();

        //destrroy node
        //
        return ;
    }

    char red = substitute->isRed();
    if(substitute == substitute->parent->left)
    {
        substitute->parent->left = x;
    }else 
    {
        substitute->parent->right = x;
    }

    if(substitute == node)  //删除节点只有一个孩子。
    {
        x->parent = substitute->parent;
    }else   // 删除节点还有两个孩子
    {
        if(substitute->parent == node)
        {
            x->parent = substitute;
        }else 
        {
            x->parent = substitute->parent;
        }

        substitute->left    = node->left;
        substitute->right   = node->left;
        substitute->parent  = node->parent;
        substitute->color   = node->color;

        if(node == T->root)
        {
            T->root = substitute;
        }else
        {
            if(node == node->parent->left)
            {
                node->parent->left = substitute;
            }else 
            {
                node->parent->right = substitute;
            }
        }
        if(substitute->left != T->sentinel)
        {
            substitute->left->parent = substitute;
        }
        if(substitute->right != T->sentinel)
        {
            substitute->right->parent = substitute;
        }
    }

    //delete node

    if(red)  return;

    //根据填充节点的信息来分类讨论.
    //此时，已知删除黑色节点。
    rbtree_node* brother = NULL;
    while(x != T->root && x->isBlack())
    {
        if(x == x->parent->left)
        {
            brother = x->parent->right;
            if(brother->isRed())
            {
                brother->black();
                brother->parent->red();
                rbtree_left_rotate(T, x->parent);

                brother = x->parent->right;
            }
            if(brother->left->isBlack() && brother->right->isBlack())
            {
                brother->red();
                x = x->parent;
            }else 
            {
                if(brother->right->isBlack())
                {
                    brother->left->black();
                    brother->red();
                    rbtree_left_rotate(T, brother);
                    brother = node->parent->right;
                }

                brother->color = x->parent->color;
                x->parent->black();
                rbtree_left_rotate(T, x->parent);
                x = T->root;
            }
        }else
        {
            brother = x->parent->left;
            if(brother->isRed())
            {
                brother->black();
                brother->parent->red();
                rbtree_right_rotate(T, brother->parent);

                brother = x->parent->right;
            }

            if(brother->left->isBlack() && brother->right->isBlack())
            {
                brother->red();
                x = x->parent;
            }else 
            {
                if(brother->left->isBlack())
                {
                    brother->right->black();
                    brother->red();
                    rbtree_left_rotate(T, brother);
                    brother = x->parent->left;
                }

                brother->color = x->parent->color;
                x->parent->black();
                brother->left->black();
                rbtree_right_rotate(T, x->parent);
                x = T->root;
            }
        }
    }
}

rbtree_node* rbtree_find(rbtree* T, int key)
{
    if(T)
    {
        rbtree_node* it = T->root;
        while(it != T->sentinel)
        {
            if(it->key == key)
            {
                return it;
            }else if(it->key > key)
            {
                it = it->left;
            }else 
            {
                it = it->right;
            }
        }

        return NULL;
    }
    return NULL;
}

int post_order(rbtree* T, rbtree_node* node, int (*visit)(int, int))
{
    if(node != T->sentinel)
    {
        int lheight = post_order(T, node->left, visit);
        int rheight = post_order(T, node->right, visit);

        return visit(lheight, rheight);
    }

    return 1; //只有root算1.
}

int post_order(rbtree* T, int (*visit)(int, int))
{
    return  post_order(T, T->root, visit);
}
