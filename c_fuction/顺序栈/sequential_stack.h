#ifndef _SEQUENTIAL_STACK_H 
#define _SEQUENTIAL_STACK_H 

#include "string.h"
#include <stdio.h>
#include <stdlib.h>
 
/* 顺序表数据类型 */
typedef int seqstack_data_t;

typedef struct 
{
    seqstack_data_t *data;    //数据区
    int top;       //目前栈顶位置,为-1表示栈为空
    int max_size;   //最大容量

}SeqStack;


void seqstack_travel_top(SeqStack *stack); //从顶部遍历栈
void seqstack_travel_bottom(SeqStack* stack); //从顶部遍历栈
/* 以上函数需要用户补充代码 */

SeqStack* seqstack_create(int max_size);//创建顺序栈
void seqstack_destroy(SeqStack *stack); //销毁顺序栈
int seqstack_push(SeqStack *stack, seqstack_data_t data); //入栈
int  seqstack_pop(SeqStack *stack, seqstack_data_t *data); //出栈
int seqstack_is_empty(SeqStack *stack); //判断是否为空
int seqstack_is_full(SeqStack *stack); //判断是否已满
int seqstack_size(SeqStack *stack); //获取当前元素个数
void seqstack_clear(SeqStack *stack); //清空栈
int seqstack_reverse(SeqStack *stack); //逆序栈
int seqstack_read(SeqStack *stack,int pos,seqstack_data_t *data); //读出栈特定位置数据

#endif
