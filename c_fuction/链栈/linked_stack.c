#include "linked_stack.h"

linkstack* linkstack_create(void)
{
    linkstack* temp;
    temp = (linkstack*)malloc(sizeof(linkstack));
    if(temp == NULL)
    {
        return NULL;
    }

    temp->top = NULL;
    temp->size = 0;

    return temp;
}


int linkstack_push(linkstack* stack, linkstack_data_t* data)
{
    if(stack == NULL || data == NULL)
    {
        return ERROR;
    }

    data->next= stack->top;
    stack->top = data;
    stack->size++;

   return OK;
}

linkstack_data_t* linkstack_pop(linkstack* stack)
{
    if(stack == NULL)
    {
        return NULL;
    }

    if(stack->size == 0)
    {
        return NULL;
    }

    linkstack_data_t* temp = stack->top;
    if(temp == NULL)
    {
        return NULL;
    }

    stack->top =  stack->top->next;
    stack->size--;

    return temp;
}

linkstack_data_t* linkstack_get(linkstack* stack,int pos)
{
    linkstack_data_t* temp=NULL;
    if(stack == NULL)
    {
        return NULL;
    }
    if(pos < 0 || pos >= stack->size)
    {
        return NULL;
    }

    temp= stack->top;
    for(int i = 0; i < pos; i++)
    {
        temp = temp->next;
    }

    return temp;
}

int linkstack_is_empty(linkstack* stack)
{
    if(stack == NULL)
    {
        return ERROR;
    }

    if(stack->size == 0)
    {
        return OK;
    }

    return NO;
}

void linkstack_destroy(linkstack* stack)
{
    linkstack_data_t* temp = NULL;
    linkstack_data_t* temp2 = NULL;
    if(stack == NULL)
    {
        return;
    }

    temp = stack->top;
    while(temp != NULL)
    {
        temp2 = temp;
        temp = temp->next;
        free(temp2);
    }

    free(stack);

}

void linkstack_clear(linkstack* stack)
{
    linkstack_data_t* temp = NULL;
    linkstack_data_t* temp2 = NULL;
    if(stack == NULL|| stack->size == 0)
    {
        return;
    }

   temp = stack->top;
   while(temp != NULL)
    {
        temp2 = temp;
        temp = temp->next;
        free(temp2);
    }

    stack->top = NULL;
    stack->size = 0;

}

int linkstack_size(linkstack* stack)
{
    if(stack == NULL)
    {
        return ERROR;
    }

    return stack->size;
}

void linkstack_treat(linkstack* stack)
{
    linkstack_data_t* temp = NULL;
    if(stack == NULL)
    {
        return;
    }

    temp = stack->top;
    while(temp != NULL)
    {
        /* user code began*/

        /* user code end*/
        temp = temp->next;
    }
    


}