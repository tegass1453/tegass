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