#ifndef _LINKED_STACK_H 
#define _LINKED_STACK_H 

#include <stdio.h>
#include <stdlib.h>

enum{
    OK = 1,
    ERROR = -1,
    NO = 0
};  // 返回值

typedef struct 
{
    /*user code began*/ 

    /*user code end*/ 
    linkstack_data_t* next;
}linkstack_data_t;  // 栈中元素类型

typedef struct 
{
    int size;        // 栈中元素个数
    linkstack_data_t* top;        // 栈顶指针

}linkstack; 

void linkstack_treat(linkstack* stack);
/* 以上函数需要用户补全代码 */

linkstack* linkstack_create(void);
int linkstack_push(linkstack* stack, linkstack_data_t* data);
linkstack_data_t* linkstack_pop(linkstack* stack);
linkstack_data_t* linkstack_get(linkstack* stack,int pos);
int linkstack_is_empty(linkstack* stack);
void linkstack_destroy(linkstack* stack);
void linkstack_clear(linkstack* stack);
int linkstack_size(linkstack* stack);




#endif
