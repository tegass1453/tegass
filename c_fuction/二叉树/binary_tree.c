#define _CRT_SECURE_NO_WARNINGS

#include "binary_tree.h"


/*
*@name:binary_tree_data_input
*@function:二叉树数据输入
*@return:数据 
*/
binary_tree_data_t* binary_tree_data_input(void)
{
    int temp = 0;
    binary_tree_data_t* data = (binary_tree_data_t*)malloc(sizeof(binary_tree_data_t));
    scanf("%d", &temp);
    if (temp == -1)
    {
        free(data);
        return NULL;
    }
    else
    {
        data->data = temp;
        return data;
    }
        
}


/*
*@name:binary_tree_create
*@function:二叉树创建
*@return:二叉树指针
*/
binary_tree* binary_tree_create(void)
{
    binary_tree_data_t* data = NULL;;
    data = binary_tree_data_input();
    if(data == NULL)
    {
        return NULL;
    }

    binary_tree* new_tree = (binary_tree*)malloc(sizeof(binary_tree));
    if(new_tree == NULL)
    {
        free(data);
        return NULL;
    }

    new_tree->data = data;
    new_tree->left=binary_tree_create();
    new_tree->right=binary_tree_create();

    return new_tree;

}

/*
*@name:binary_tree_visit
*@function:二叉树节点访问
*@return:无
*@param:tree 二叉树指针 level 层级
*/
void binary_tree_visit(binary_tree* tree,int level)
{
    if(tree == NULL)
    {
        return;
    }

    printf("第%d层 数据为%d\n", level, tree->data->data);
}


/*
*@name:binary_tree_traverse
*@function:二叉树遍历
*@return:无
*@param:tree 二叉树指针 level 当前层级
*/
int  binary_tree_traverse(binary_tree* tree,int level)
{
    if(tree == NULL)
    {
        return ERROR;
    }

    binary_tree_visit(tree,level);
    binary_tree_traverse(tree->left, level+1);
    binary_tree_traverse(tree->right, level + 1);


    return OK;

}