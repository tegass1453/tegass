#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>


/*
* ��ģ������й��ܾ�Ϊǰ��ʵ�֣���Ҫ����˳������ͱ���
*/

/* ״̬������ */
enum{
   OK=1,
   ERROR=-1,
   NO=0
}; 

/* ���ݶ����� */
typedef struct binary_tree_data_t {
   int data;

}binary_tree_data_t;


/* ������������ */
typedef struct binary_tree{

    binary_tree_data_t *data; 
    struct binary_tree* left;
    struct binary_tree* right;

}binary_tree;

/* ���������� */
binary_tree_data_t* binary_tree_data_input(void);
void binary_tree_visit(binary_tree* tree,int level);
/* ���Ϻ�����Ҫ������� */

binary_tree* binary_tree_create(void);
int  binary_tree_traverse(binary_tree* tree,int level);


#endif
