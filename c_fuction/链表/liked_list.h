#ifndef _LIKEDLIST_APP
#define _LIKEDLIST_APP

#include "stdio.h"
#include <stdlib.h>

#define linklist list_name
#define head list_head_name
#define tail list_tail_name
 
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
void  linklist_init(linklist* struc_p);/*��Ҫ�û��Զ���*/
void linklist_del(linklist* list);
unsigned char linklist_deltopool(linklist* list);
void likelink_insert_end(linklist* insert_list);
unsigned char linklist_new(linklist** struc_p);


#endif
