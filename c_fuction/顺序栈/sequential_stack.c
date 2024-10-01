#include "sequential_stack.h"

/*
*@function:seqstack_travel_bottom
*@description:从顶部开始遍历顺序栈
*@param:stack:顺序栈指针
*@return:无
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
*@description:从底部开始遍历顺序栈
*@param:stack:顺序栈指针
*@return:无
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
*@description:创建顺序栈
*@param:stack:顺序栈指针
*@param:max_size:顺序栈最大容量
*@return:创建的顺序栈的地址，NULL-创建失败
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
*@description:销毁顺序栈
*@param:stack:顺序栈指针
*@return:无
*/
void seqstack_destroy(SeqStack *stack)
{
    free(stack->data);
    free(stack);

}



/*
*@function:seqstack_push
*@description:向顺序栈中压入数据
*@param:stack:顺序栈指针
*@param:data:要压入的数据
*@return:0:成功，-1:失败
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
*@description:从顺序栈中弹出数据
*@param:stack:顺序栈指针
*@param:data:要弹出的数据接收地址
*@return:0:成功，-1:失败
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
*@description:判断顺序栈是否为空
*@param:stack:顺序栈指针
*@return:1:空，0:非空，-1:失败
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
*@description:判断顺序栈是否已满
*@param:stack:顺序栈指针
*@return:1:满，0:非满，-1:失败
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
*@description:获取顺序栈中现有数据个数
*@param:stack:顺序栈指针
*@return:顺序栈中数据个数，-1:失败
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
*@description:清空顺序栈
*@param:stack:顺序栈指针
*@return:无
*/
void seqstack_clear(SeqStack *stack)
{
    stack->top=-1;
}


/*
*@function:seqstack_reverse
*@description:将顺序栈中的数据逆序
*@param:stack:顺序栈指针,此后stack中的数据顺序与入栈顺序相反
*@return: -1:失败，0:成功
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
*@description:读取顺序栈中指定位置的数据
*@param:stack:顺序栈指针,pos:要读取的位置,data:存储读取的数据
*@return:0:成功,-1:失败
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