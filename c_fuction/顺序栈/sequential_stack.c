#include "sequential_stack.h"

/*
*@function:seqstack_travel_bottom
*@description:�Ӷ�����ʼ����˳��ջ
*@param:stack:˳��ջָ��
*@return:��
*/
void seqstack_travel_top(SeqStack* stack)
{
    int i = 0;
    for  (i = stack->top; i>=0 ; i--)
    {
        /* user code start */


        /* user code end */
    }
}

/*
*@function:seqstack_travel_bottom
*@description:�ӵײ���ʼ����˳��ջ
*@param:stack:˳��ջָ��
*@return:��
*/
void seqstack_travel_bottom(SeqStack* stack)
{
    int i = 0;
    for (i = 0; i <= stack->top; i++)
    {
        /* user code start */


        /* user code end */
    }
}


/*
*@function:seqstack_create
*@description:����˳��ջ
*@param:stack:˳��ջָ��
*@param:max_size:˳��ջ�������
*@return:������˳��ջ�ĵ�ַ��NULL-����ʧ��
*/
SeqStack* seqstack_create(int max_size)
{
    SeqStack* temp= (SeqStack*)malloc(sizeof(SeqStack));
    if(temp==NULL)
    {
        return NULL;

    }
    temp->data=(seqstack_data_t*)malloc(sizeof(seqstack_data_t)*max_size);
    if(temp->data==NULL)
    {
        free(temp);
        return NULL;
    }

    memset(temp->data,0,sizeof(seqstack_data_t)*max_size);

    temp->max_size=max_size;
    temp->top=-1;
    return temp;
}



/*@function:seqstack_destroy
*@description:����˳��ջ
*@param:stack:˳��ջָ��
*@return:��
*/
void seqstack_destroy(SeqStack *stack)
{
    free(stack->data);
    free(stack);

}



/*
*@function:seqstack_push
*@description:��˳��ջ��ѹ������
*@param:stack:˳��ջָ��
*@param:data:Ҫѹ�������
*@return:0:�ɹ���-1:ʧ��
*/
int seqstack_push(SeqStack *stack, seqstack_data_t data)
{
    if(stack->top==stack->max_size-1)
    {
        fprintf(stderr,"stack is full\n");
        return -1;
    }

    stack->top++;
    stack->data[stack->top]=data;
    

    return 0;
}

/*
*@function:seqstack_pop
*@description:��˳��ջ�е�������
*@param:stack:˳��ջָ��
*@param:data:Ҫ���������ݽ��յ�ַ
*@return:0:�ɹ���-1:ʧ��
*/
int  seqstack_pop(SeqStack *stack, seqstack_data_t *data)
{
    if(stack->top==-1)
    {
        fprintf(stderr,"stack is empty\n");
        return -1;
    }

    *data=stack->data[stack->top];
    stack->top--;
    return 0;

}

/*
*@function:seqstack_is_empty
*@description:�ж�˳��ջ�Ƿ�Ϊ��
*@param:stack:˳��ջָ��
*@return:1:�գ�0:�ǿգ�-1:ʧ��
*/
int seqstack_is_empty(SeqStack *stack)
{
    if(stack==NULL)
    {
        fprintf(stderr,"stack is null\n");
        return -1;
    }
    else if(stack->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


/*
*@function:seqstack_is_full
*@description:�ж�˳��ջ�Ƿ�����
*@param:stack:˳��ջָ��
*@return:1:����0:������-1:ʧ��
*/
int seqstack_is_full(SeqStack *stack)
{
    if(stack==NULL)
    {
        fprintf(stderr,"stack is null\n");
        return -1;
    }
    else if(stack->top==stack->max_size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
*@function:seqstack_size
*@description:��ȡ˳��ջ���������ݸ���
*@param:stack:˳��ջָ��
*@return:˳��ջ�����ݸ�����-1:ʧ��
*/
int seqstack_size(SeqStack *stack)
{
    if(stack==NULL)
    {
        fprintf(stderr,"stack is null\n");
        return -1;
    }
    else
    {
        return stack->top+1;
    }
}


/*
*@function:seqstack_clear
*@description:���˳��ջ
*@param:stack:˳��ջָ��
*@return:��
*/
void seqstack_clear(SeqStack *stack)
{
    stack->top=-1;
}


/*
*@function:seqstack_reverse
*@description:��˳��ջ�е���������
*@param:stack:˳��ջָ��,�˺�stack�е�����˳������ջ˳���෴
*@return: -1:ʧ�ܣ�0:�ɹ�
*/
int seqstack_reverse(SeqStack *stack)
{
    int i = 0;
    seqstack_data_t temp;

    if(stack==NULL)
    {
        fprintf(stderr,"stack is null\n");
        return -1;
    }
    else
    {
        for (i = 0;; i++)
        {
            temp = stack->data[i];
            stack->data[i] = stack->data[stack->top - i];
            stack->data[stack->top - i] = temp;
            if (i >= stack->top - i)
            {
                break;
            }
        }
    }
    return 0;
}


/*
*@function:seqstack_read
*@description:��ȡ˳��ջ��ָ��λ�õ�����
*@param:stack:˳��ջָ��,pos:Ҫ��ȡ��λ��,data:�洢��ȡ������
*@return:0:�ɹ�,-1:ʧ��
*/
int seqstack_read(SeqStack *stack,int pos,seqstack_data_t *data)
{
    if(stack==NULL)
    {
        fprintf(stderr,"stack is null\n");
        return -1;
    }
    else if(pos<0||pos>stack->top)
    {
        fprintf(stderr,"pos is out of range\n");
        return -1;
    }

    *data=stack->data[pos];
    return 0;
}