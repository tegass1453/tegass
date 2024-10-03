#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>


/*
* ��ģ��Ĵ�������Ϊǰ��ʵ��
*/

/* ״̬������ */
enum{
   OK=1,
   ERROR=-1,
   NO=0
}; 

enum{
   threaded=1,
   linked=0,
}; 

/* ���ݶ����� */
typedef struct binary_tree_data_t {
   int data;

}binary_tree_data_t;


/* ������������ */
typedef struct binary_tree{

    binary_tree_data_t *data; 
    unsigned char ltag;
    unsigned char rtag;
    struct binary_tree* left;
    struct binary_tree* right;

}binary_tree;

/* ���������� */
binary_tree_data_t* binary_tree_data_input(void);
void binary_tree_visit(binary_tree* tree,int level);
/* ���Ϻ�����Ҫ������� */

binary_tree* binary_tree_create(void); //������������(ǰ��˳����������)
int  binary_tree_preordertraverse(binary_tree* tree,int level); //ǰ�����
void binaryTree_threaded(binary_tree* tree); //������������
int  binary_tree_inordertraverse(binary_tree* tree); //�������,Ч�ʸ�

#endif
