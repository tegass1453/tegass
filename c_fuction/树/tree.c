#include "tree.h"
/*
*@name : tree_create
*@brief: ����һ����
*@param: size - ���Ĵ�С
*@return: tree* -�½�����ָ��
*/
tree* tree_create(int size)
{
    tree* new_tree = (tree*)malloc(sizeof(tree));
    if(new_tree == NULL)
    {
        return NULL;
    }

    new_tree->size = size;
    new_tree->root = -1;

    new_tree->tree_nodes = (tree_node*)malloc(sizeof(tree_node)*size);
    if(new_tree->tree_nodes == NULL)
    {
        free(new_tree);
        return NULL;
    }

    return new_tree;
}

/*
*@name : tree_destroy
*@brief: ������
*@param: tree* - ����ָ��
*@return: void
*/
void tree_destroy(tree* tree)
{
    free(tree->tree_nodes);
    free(tree);
}


/*
*@name : tree_add_child
*@brief: ����ӽڵ�
*@param: tree* - ����ָ��
*@param: parent - ���ڵ������
*@param: self_index - �ӽڵ������
*@return: int - OK or ERROR
*/
int  tree_add_child(tree* tree, int parent, int self_index)
{
    child_node* temp=NULL;
   if(tree == NULL)
   {
       return ERROR;
   }
   if(parent >= tree->size || self_index >= tree->size)
   {
       return ERROR;
   }

    tree->size++;
    tree->tree_nodes[self_index].parent = parent;

    if(tree->tree_nodes[parent].first_child == NULL)
    {
        tree->tree_nodes[parent].first_child = &(tree->tree_nodes[self_index]);
    }
    else
    {
        temp = tree->tree_nodes[parent].first_child;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next = &(tree->tree_nodes[self_index]);

    }

    temp->self_index = self_index;

    return OK;

}