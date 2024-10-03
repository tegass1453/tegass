#define _CRT_SECURE_NO_WARNINGS

#include "binary_tree.h"


/*
*@name:binary_tree_data_input
*@function:��������������
*@return:���� 
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
*@function:����������
*@return:������ָ��
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
*@function:�������ڵ����
*@return:��
*@param:tree ������ָ�� level �㼶
*/
void binary_tree_visit(binary_tree* tree,int level)
{
    if(tree == NULL)
    {
        return;
    }

    printf("��%d�� ����Ϊ%d\n", level, tree->data->data);
}


/*
*@name:binary_tree_traverse
*@function:����������
*@return:��
*@param:tree ������ָ�� level ��ǰ�㼶
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
*@note: ����������binaryTree_threaded����������������������Ч�����
*@name:binary_tree_inordertraverse
*@function:�������������
*@return:��
*@param:tree ������ָ��
*/
int  binary_tree_inordertraverse(binary_tree* tree)
{
    if (tree == NULL)
	{
		return ERROR;
	}
	binary_tree* temp = tree;
	//���ҵ�����߽�� Ȼ�����������ֱ�����ұ���
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
*@function:������������
*@return:��
*@param:tree ������ָ��
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