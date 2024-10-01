#include "linked_queue.h"


/*
*@name:linkqueue_create
*@brief:创建一个队列
*@return:返回一个队列指针 NULL表示创建失败
*/
linkqueue* linkqueue_create(void)
{
    linkqueue* q = (linkqueue*)malloc(sizeof(linkqueue));
    if (q == NULL) {
        return NULL;
    }

    q->front = q->rear = NULL;
    q->size = 0;

    return q;
}


/*
*@name:linkqueue_enqueue
*@brief:入队
*@param:queue 队列指针 data 入队的数据
*@return:返回OK表示成功 ERROR表示失败
*/
int linkqueue_enqueue(linkqueue* queue, linkqueue_data_t* data)
{
    if (queue == NULL || data == NULL) {
        return ERROR;
    }

    linkqueue_data_t* node = (linkqueue_data_t*)malloc(sizeof(linkqueue_data_t));
    if (node == NULL) {
        return ERROR;
    }

    queue->size++;

    if(queue->rear == NULL) 
    {
        queue->front = queue->rear = node;
    }
    else
    {
        queue->rear->next = node;
        queue->rear = node;
    }

    return OK;
}


/*
*@name:linkqueue_dequeue
*@brief:出队
*@param:queue 队列指针 data 出队的数据
*@return: NULL表示失败 成功返回出队的数据指针
*/
linkqueue_data_t* linkqueue_dequeue(linkqueue* queue, linkqueue_data_t* data)
{
    if (queue == NULL || data == NULL) {
        return NULL;
    }

    if (queue->front == NULL) {
        return NULL;
    }

    queue->size--;
    queue->front = queue->front->next;

    return data;
}


/*
*@name:linkqueue_is_empty
*@brief:判断队列是否为空
*@param:queue 队列指针
*@return:返回OK表示为空 NO表示不为空,ERROR表示失败
*/
int linkqueue_is_empty(linkqueue* queue)
{
    if (queue == NULL) {
        return ERROR;
    }

    if (queue->size == NULL) {
        return OK;
    }
    else {
        return NO;
    } 
}

/*
*@name:linkqueue_size
*@brief:获取队列大小
*@param:queue 队列指针
*@return:返回队列大小 ERROR表示失败
*/
int linkqueue_size(linkqueue* queue)
{
    if (queue == NULL) {
        return ERROR;
    }

    return queue->size;
}

/*
*@name:linkqueue_destroy
*@brief:销毁队列
*@param:queue 队列指针
*@return:无
*/
void linkqueue_destroy(linkqueue* queue)
{
     linkqueue_data_t*node;
     linkqueue_data_t* next;
    if (queue == NULL) {
        return;
    }

    node = queue->front;
    while (node != NULL) {
        next = node->next;
        free(node);
        node = next;
    }

    free(queue);

}

/*
*@name:linkqueue_treat
*@brief:遍历队列
*@param:queue 队列指针
*@return:无
*/
void linkqueue_treat(linkqueue* queue)
{
    linkqueue_data_t* node;
    if (queue == NULL) {
        return;
    }

     node = queue->front;
    while (node != NULL) 
    {
        /*user code began*/

        /*user code end*/
        node = node->next;
    }

}