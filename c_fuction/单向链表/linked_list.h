#pragma once
/*若编译器不支持，请删除上行，启用ifndef方式*/
/*
#ifndef _LINKEDLIST_APP
#define _LINKEDLIST_APP
*/

#include "stdio.h"
#include <stdlib.h>

/*链表名称定义区*/
#define linklist list_name
#define head list_head_name

/*链表定义区*/
typedef struct link_list
{
/*user struct code start*/
 int ID;
/*user struct code end*/
   struct link_list * next;
}linklist;

/*链表删除池*/
linklist* linkpoolhead;

/*链表头节点和尾节点*/
linklist *head;


/*单向链表函数*/
void  linklist_traverse_down(linklist* struc_p);
void  linklist_init(linklist* struc_p);
unsigned char linklist_insert_if(linklist* insert_list);
/*上述函数需要用户添加代码*/
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
