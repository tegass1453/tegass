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

/*链表删除池*/
linklist* linkpoolhead;

/*链表头节点和尾节点*/
linklist *head,*tail;


/*双向链表函数*/
void  linklist_init(linklist* struc_p);/*需要用户自定义*/
void linklist_del(linklist* list);
unsigned char linklist_deltopool(linklist* list);
void likelink_insert_end(linklist* insert_list);
unsigned char linklist_new(linklist** struc_p);


#endif
