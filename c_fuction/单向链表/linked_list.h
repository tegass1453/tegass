#pragma once
/*����������֧�֣���ɾ�����У�����ifndef��ʽ*/
/*
#ifndef _LINKEDLIST_APP
#define _LINKEDLIST_APP
*/

#include "stdio.h"
#include <stdlib.h>

/*�������ƶ�����*/
#define linklist list_name
#define head list_head_name

/*��������*/
typedef struct link_list
{
/*user struct code start*/
 int ID;
/*user struct code end*/
   struct link_list * next;
}linklist;

/*����ɾ����*/
linklist* linkpoolhead;

/*����ͷ�ڵ��β�ڵ�*/
linklist *head;


/*����������*/
void  linklist_traverse_down(linklist* struc_p);
void  linklist_init(linklist* struc_p);
unsigned char linklist_insert_if(linklist* insert_list);
/*����������Ҫ�û���Ӵ���*/
void linklist_insert_end(linklist* insert_list);
void linklist_insert_head(linklist* insert_list);
unsigned char linklist_new_end(void);
unsigned char linklist_new_head(void);
linklist* linklist_new(void);
unsigned char linklist_deltopool(linklist* list);
void linkpoolhead_free(int num);

/*
#endif
*/
