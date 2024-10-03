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
    new_tree->ltag = linked;
    new_tree->rtag = linked;

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
int  binary_tree_preordertraverse(binary_tree* tree,int level)
{
    if(tree == NULL)
    {
        return ERROR;
    }

    binary_tree_visit(tree,level);
    if(tree->ltag == linked && tree->left!=NULL)
        binary_tree_preordertraverse(tree->left, level+1);
    if (tree->rtag == linked&&tree->right!=NULL )
        binary_tree_preordertraverse(tree->right, level + 1);


    return OK;

}


/*
*@note: 必须先运行binaryTree_threaded函数进行线索化，本遍历效率最高
*@name:binary_tree_inordertraverse
*@function:二叉树中序遍历
*@return:无
*@param:tree 二叉树指针
*/
int  binary_tree_inordertraverse(binary_tree* tree)
{
    if (tree == NULL)
	{
		return ERROR;
	}
	binary_tree* temp = tree;
	//先找到最左边结点 然后根据线索化直接向右遍历
	while (temp != NULL && temp->ltag == linked)
	{
		temp = temp->left;
	}
	while (temp != NULL)
	{
		binary_tree_visit(temp, 0);
		temp = temp->right;
	}

    return OK;

}


/*
*@name:binaryTree_threaded
*@function:二叉树线索化
*@return:无
*@param:tree 二叉树指针
*/
void binaryTree_threaded(binary_tree* tree)
{
    static binary_tree* pre = NULL;

   if(tree == NULL)
   {
        return ;
   }

   if( tree->left != NULL)
        binaryTree_threaded(tree->left);

   if( pre == NULL)
   {
        pre=tree;
   }
   else if(pre->right == NULL)
   {
        pre->right = tree;
        pre->rtag = threaded;
   }

   if(tree->left == NULL)
   {
        tree->left = pre;
        tree->ltag = threaded;
   }

   pre = tree;

   if(tree->left != NULL)
         binaryTree_threaded(tree->right);

}