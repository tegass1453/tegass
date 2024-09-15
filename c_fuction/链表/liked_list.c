#include "liked_list.h"

void  linklist_init(linklist* struc_p)
{

}
unsigned char linklist_new(linklist** struc_p)
{
   linklist* temp;

    temp=(linklist*)malloc(sizeof(linklist));
    if(temp==NULL)
        return 0;
    
    temp->next=NULL;
    temp->last=NULL;
    *struc_p=temp;
    
    return 1;
}

void linklist_insert_end(linklist* insert_list)
{
    if(tail==NULL)
    {
        tail=insert_list;
        head=insert_list;
    }
    else 
    {
        tail->next=insert_list;
        insert_list->last=tail;
        tail=insert_list;
    }

}
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
void linklist_del(linklist* list)
{
    linklist* temp;
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
    free(list);
}