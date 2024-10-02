#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

enum{
   OK=1,
   ERROR=-1,
   NO=0
};

typedef struct{
   int data;

}binary_tree_data_t;

typedef struct  {
    binary_tree_data_t *data;
    
    struct binary_tree_node *left;
    struct binary_tree_node *right;

}binary_tree_node;

typedef struct  {
    binary_tree_node* root;
    int size;
}binary_tree;

binary_tree* binary_tree_create(void);
int binary_tree_insert (binary_tree* tree, binary_tree_data_t* data);

#endif
