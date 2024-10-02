#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>


/*
* 本模块的所有功能均为前序实现，需要按照顺序输入和遍历
*/

/* 状态定义区 */
enum{
   OK=1,
   ERROR=-1,
   NO=0
}; 

/* 数据定义区 */
typedef struct binary_tree_data_t {
   int data;

}binary_tree_data_t;


/* 二叉树定于区 */
typedef struct binary_tree{

    binary_tree_data_t *data; 
    struct binary_tree* left;
    struct binary_tree* right;

}binary_tree;

/* 函数定义区 */
binary_tree_data_t* binary_tree_data_input(void);
void binary_tree_visit(binary_tree* tree,int level);
/* 以上函数需要补充代码 */

binary_tree* binary_tree_create(void);
int  binary_tree_traverse(binary_tree* tree,int level);


#endif
