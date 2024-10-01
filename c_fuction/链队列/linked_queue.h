#ifndef _LINKED_queue_H 
#define _LINKED_queue_H 

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
    linkqueue_data_t* next;
}linkqueue_data_t;  // 栈中元素类型

typedef struct 
{
    int size;        // 栈中元素个数
    linkqueue_data_t* rear;        // 队尾指针
    linkqueue_data_t* front;        // 队尾指针

}linkqueue; 


void linkqueue_treat(linkqueue* queue); // 遍历队列

linkqueue* linkqueue_create(void);  // 创建队列
int linkqueue_enqueue(linkqueue* queue, linkqueue_data_t* data); // 入队
linkqueue_data_t* linkqueue_dequeue(linkqueue* queue, linkqueue_data_t* data); // 出队
int linkqueue_is_empty(linkqueue* queue); // 判断队列是否为空
int linkqueue_size(linkqueue* queue); // 获取队列中元素个数
void linkqueue_destroy(linkqueue* queue); // 销毁队列







#endif
