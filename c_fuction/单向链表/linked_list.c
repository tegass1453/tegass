#include "linked_list.h"
/**
 * @brief  找到链表尾节点
 * @param  struc_p    开始遍历点的链表地址
 * @retval None
 */
linklist* linklist_find_tail(linklist* struc_p)
{
    while (struc_p != NULL)
    {
        struc_p = struc_p->next;
    }
    return struc_p;
}

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
    linklist* temp=head;
    if (head== NULL)
    {
        head = insert_list;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=insert_list;
    }

}

/**
 * @brief  在头部插入一个链表
 * @param  insert_list  要插入的链表地址
 * @retval None
 */
void linklist_insert_head(linklist* insert_list)
{
    insert_list->next=NULL;
    if (head == NULL)
    {
        head = insert_list;
    }
    else
    {
       insert_list->next=head;
       head=insert_list;
    }

}


/**
 * @brief  在符合条件处插入一个链表
 * @param  insert_list  要插入的链表地址
 * @retval 0-失败 1-成功
 */
unsigned char linklist_insert_if(linklist* insert_list)
{
    insert_list->next=NULL;
    linklist* temp=head;
    linklist* temp1=NULL;

    if (head == NULL)
    {
        head = insert_list;
    }
    else
    {
        while(temp!=NULL)
        {
             /*以下写入条件判断和退出循环,若符合条件，插入到其前*/
            /*user struct code start*/
            if (insert_list->ID > temp->ID)
                break;
             /*user struct code end*/
            temp1=temp;      
            temp=temp->next;
            if(temp==NULL)return 0;
        }
        if(temp==NULL)
            return;
        else if(temp==head)
            linklist_insert_head(insert_list);
        else 
        {
            temp1->next=insert_list;
            insert_list->next=temp;
        }
    }
    return 1;
}

/**
 * @brief  新创建一个链表，并插入链表末尾
 * @param  struc_p    要初始化的链表地址
 * @retval 1-成功，0-失败
 */
unsigned char linklist_new_end(void)
{
        linklist* temp=linklist_new();
        if(temp==NULL)
            return 0;
        linklist_insert_end(temp);
        return 1;
}

/**
 * @brief  新创建一个链表，并插入链表头部
 * @param  struc_p    要初始化的链表地址
 * @retval 1-成功，0-失败
 */
unsigned char linklist_new_head(void)
{
        linklist* temp=linklist_new();
        if(temp==NULL)
            return 0;
        linklist_insert_head(temp);
        return 1;
}

/**
 * @brief  新创建一个链表，并返回其地址
 * @param  struc_p    要初始化的链表地址
 * @retval linklist* 链表地址
 */
linklist* linklist_new(void)
{
   linklist* temp;
   if(linkpoolhead==NULL)
   {
    temp=(linklist*)malloc(sizeof(linklist));
    if(temp==NULL)
        return NULL;
    temp->next=NULL;
    return temp;
   }
   else 
   {
        temp=linkpoolhead;
        linkpoolhead=linkpoolhead->next;
        temp->next=NULL;
        return temp;
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
  
  if(list==NULL)return 0;
  if(list==head)
  {
    head=head->next;
  }
  else 
  {
        while(temp->next!=list)
        {
            temp=temp->next;
            if(temp==NULL)
                return 0;
        }
        temp->next=list->next;     
  }

    if(linkpoolhead==NULL)
    {
        linkpoolhead=list;
        list->next=NULL;
    }
    else 
    {     
        list->next=linkpoolhead;
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