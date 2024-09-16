#include "liked_list.h"

/**
 * @brief  对链表进行向下遍历
 * @param  struc_p    开始遍历点的链表地址
 * @retval None
 */
void  linklist_traverse_down(linklist* struc_p)
{
   do{
       /*user struct code start*/

    /*user struct code end*/
        struc_p = struc_p->next;
    } while (struc_p!= NULL);
    
}

/**
 * @brief  对链表进行向上遍历
 * @param  struc_p    开始遍历点的链表地址
 * @retval None
 */
void  linklist_traverse_up(linklist* struc_p)
{
    do {
        /*user struct code start*/

        /*user struct code end*/
        struc_p = struc_p->last;
    } while (struc_p != NULL);

}

/**
 * @brief  对新创建的链表进行初始化
 * @param  struc_p    要初始化的链表地址
 * @retval None
 */
void  linklist_init(linklist* struc_p)
{

}

/**
 * @brief  在末尾插入一个链表
 * @param  insert_list  要插入的链表地址
 * @retval None
 */
void linklist_insert_end(linklist* insert_list)
{
    if (tail == NULL)
    {
        tail = insert_list;
        head = insert_list;
    }
    else
    {
        tail->next = insert_list;
        insert_list->last = tail;
        tail = insert_list;
    }

}

/**
 * @brief  新创建一个链表，并插入链表末尾
 * @param  struc_p    要初始化的链表地址
 * @retval 1-成功，0-失败
 */
unsigned char linklist_new(void)
{
   linklist* temp;
   if(linkpoolhead==NULL)
   {
    temp=(linklist*)malloc(sizeof(linklist));
    if(temp==NULL)
        return 0;
    
    temp->next=NULL;
    temp->last=NULL;
    linklist_insert_end(temp);

    return 1;
   }
   else 
   {
        temp=linkpoolhead;
        linkpoolhead=linkpoolhead->next;
        temp->next=NULL;
        linklist_insert_end(temp);
        return 1;

   }
}



/**
 * @brief  将一个链表删除到链表池
 * @param  list  要删除的链表地址
 * @retval  1-成功，0-失败
 */
unsigned char linklist_deltopool(linklist* list)
{
  linklist* temp=head;

  if(head->next==NULL)
  {
    head=NULL;
    tail=NULL;
  }
 else 
 {
    temp=list->last;
    temp->next=list->next;
    
    temp=list->next;
    temp->last=list->last;

 }

    if(linkpoolhead==NULL)
    {
        linkpoolhead=list;
        list->last=NULL;
        list->next=NULL;
    }
    else 
    {     
        list->next=linkpoolhead;
        list->last=NULL;
        linkpoolhead=list;
    }
    return 1;
}
/**
 * @brief  释放链表池内存
 * @param  num  要释放的链表数量
 * @retval None
 */
void linkpoolhead_free(int num)
{
    linklist* temp;
    while (num--)
    {
        if (linkpoolhead == NULL)break;
        temp = linkpoolhead;
        linkpoolhead = linkpoolhead->next;
        free(temp);
    }
}