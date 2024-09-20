#include "liked_list.h"

/**
 * @brief  ������������±���
 * @param  struc_p    ��ʼ������������ַ
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
 * @brief  ������������ϱ���
 * @param  struc_p    ��ʼ������������ַ
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
 * @brief  ���´�����������г�ʼ��
 * @param  struc_p    Ҫ��ʼ���������ַ
 * @retval None
 */
void  linklist_init(linklist* struc_p)
{

}

/**
 * @brief  ��ĩβ����һ������
 * @param  insert_list  Ҫ����������ַ
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
 * @brief  ��ͷ������һ������
 * @param  insert_list  Ҫ����������ַ
 * @retval None
 */
void linklist_insert_head(linklist* insert_list)
{
    insert_list->last=NULL;
    insert_list->next=NULL;
    if (tail == NULL)
    {
        tail = insert_list;
        head = insert_list;
    }
    else
    {
        head->last=insert_list;
        insert_list->next=head;
        head=insert_list;
    }

}


/**
 * @brief  �ڷ�������������һ������
 * @param  insert_list  Ҫ����������ַ
 * @retval None
 */
void linklist_insert_if(linklist* insert_list)
{
    insert_list->last=NULL;
    insert_list->next=NULL;
    linklist* temp=head;

    if (tail == NULL)
    {
        tail = insert_list;
        head = insert_list;
    }
    else
    {
        while(temp!=NULL)
        {
             /*����д�������жϺ��˳�ѭ��,���������������뵽��ǰ*/
            /*user struct code start*/
            
             /*user struct code end*/      
            temp=temp->next;
        }
        if(temp==head)
            {
                temp->last=insert_list;
                insert_list->next=temp;
                head=temp;
            }
        else 
        {
            (temp->last)->next=insert_list;
            insert_list->last=temp->last;
            insert_list->next=temp;
            temp->last=insert_list;
        }
            
    }

}

/**
 * @brief  �´���һ����������������ĩβ
 * @param  struc_p    Ҫ��ʼ���������ַ
 * @retval 1-�ɹ���0-ʧ��
 */
unsigned char linklist_new_end(void)
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
 * @brief  �´���һ���������������ַ
 * @param  struc_p    Ҫ��ʼ���������ַ
 * @retval linklist* �����ַ
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
    temp->last=NULL;
    return temp;

    return 1;
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
 * @brief  ��һ������ɾ���������
 * @param  list  Ҫɾ���������ַ
 * @retval  1-�ɹ���0-ʧ��
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
 * @brief  �ͷ�������ڴ�
 * @param  num  Ҫ�ͷŵ���������
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