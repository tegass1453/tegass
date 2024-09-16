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
 * @brief  �´���һ����������������ĩβ
 * @param  struc_p    Ҫ��ʼ���������ַ
 * @retval 1-�ɹ���0-ʧ��
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