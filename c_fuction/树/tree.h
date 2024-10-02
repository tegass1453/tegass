#ifndef _TREE_H
#define _TREE_H

#include "stdio.h"
#include <stdlib.h>

enum{
   OK=1,
   ERROR=-1,
   NO=0
};

typedef struct{
   int a;
}tree_data_t;

typedef struct 
{
    int self_index;  //index of the node
    child_node* next;   

}child_node;

typedef struct 
{
    tree_data_t data;   
    int parent;
    child_node* first_child;
   
}tree_node;

typedef struct{
   tree_node* tree_nodes;
   int root;
   int size;
}tree;

tree* tree_create(int size);
void tree_destroy(tree* tree);
int  tree_add_child(tree* tree, int parent, int self_index);

#endif
