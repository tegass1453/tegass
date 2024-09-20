#ifndef _LINKDLIST_APP
#define _LINKDLIST_APP

#include "stdio.h"
#include <stdlib.h>

/*�������ƶ�����*/
#define linklist list_name
#define head list_head_name
#define tail list_tail_name

/*��������*/
typedef struct link_list
{
/*user struct code start*/

/*user struct code end*/
   struct link_list * next;
   struct link_list * last;

}linklist;

/*����ɾ����*/
linklist* linkpoolhead;

/*����ͷ�ڵ��β�ڵ�*/
linklist *head,*tail;


/*˫��������*/
void  linklist_traverse_down(linklist* struc_p);
void  linklist_traverse_up(linklist* struc_p);
void  linklist_init(linklist* struc_p);
void linklist_insert_if(linklist* insert_list);
/*����������Ҫ�û���Ӵ���*/
void linklist_insert_end(linklist* insert_list);
unsigned char linklist_new_end(void);
unsigned char linklist_deltopool(linklist* list);
void linkpoolhead_free(int num);
void linklist_insert_head(linklist* insert_list);
linklist* linklist_new(void);
linklist* linklist_find_tail(linklist* struc_p);
linklist* linklist_find_tail(linklist* struc_p);

#endif
