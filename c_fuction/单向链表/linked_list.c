#include "linked_list.h"
/**
 * @brief  �ҵ�����β�ڵ�
 * @param  struc_p    ��ʼ������������ַ
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
 * @brief  ��ͷ������һ������
 * @param  insert_list  Ҫ����������ַ
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
 * @brief  �ڷ�������������һ������
 * @param  insert_list  Ҫ����������ַ
 * @retval 0-ʧ�� 1-�ɹ�
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
             /*����д�������жϺ��˳�ѭ��,���������������뵽��ǰ*/
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
 * @brief  �´���һ����������������ĩβ
 * @param  struc_p    Ҫ��ʼ���������ַ
 * @retval 1-�ɹ���0-ʧ��
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
 * @brief  �´���һ����������������ͷ��
 * @param  struc_p    Ҫ��ʼ���������ַ
 * @retval 1-�ɹ���0-ʧ��
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
 * @brief  ��һ������ɾ���������
 * @param  list  Ҫɾ���������ַ
 * @retval  1-�ɹ���0-ʧ��
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