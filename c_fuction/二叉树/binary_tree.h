#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>


/*
* 本模块的创建功能为前序实现
*/

/* 状态定义区 */
enum{
   OK=1,
   ERROR=-1,
   NO=0
}; 

enum{
   threaded=1,
   linked=0,
}; 

/* 数据定义区 */
typedef struct binary_tree_data_t {
   int data;

}binary_tree_data_t;


/* 二叉树定于区 */
typedef struct binary_tree{

    binary_tree_data_t *data; 
    unsigned char ltag;
    unsigned char rtag;
    struct binary_tree* left;
    struct binary_tree* right;

}binary_tree;

/* 函数定义区 */
binary_tree_data_t* binary_tree_data_input(void);
void binary_tree_visit(binary_tree* tree,int level);
/* 以上函数需要补充代码 */

binary_tree* binary_tree_create(void); //创建二叉树，(前序顺序输入数据)
int  binary_tree_preordertraverse(binary_tree* tree,int level); //前序遍历
void binaryTree_threaded(binary_tree* tree); //线索化二叉树
int  binary_tree_inordertraverse(binary_tree* tree); //中序遍历,效率高

#endif
