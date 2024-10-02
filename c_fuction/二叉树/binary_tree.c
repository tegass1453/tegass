#include "binary_tree.h"

binary_tree* binary_tree_create(void)
{
    binary_tree* new_tree = (binary_tree*)malloc(sizeof(binary_tree));
    if(new_tree == NULL)
    {
        return NULL;
    }

    new_tree->size = 0;
    new_tree->root = NULL;

    return new_tree;
}

int binary_tree_insert (binary_tree* tree, binary_tree_data_t* data)
{
    if(tree == NULL||data==NULL)
    {
        return ERROR;
    }

    if(tree->root == NULL)
    {
        tree->root = (binary_tree_node*)malloc(sizeof(binary_tree_node));
        if(tree->root == NULL)
        {
            return ERROR;
        }

        tree->root->data = data;
        tree->root->left = NULL;
        tree->root->right = NULL;

        return OK;
    }
    else 
    {
        return OK;
    }

}