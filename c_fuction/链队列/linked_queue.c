#include "linked_queue.h"


/*
*@name:linkqueue_create
*@brief:����һ������
*@return:����һ������ָ�� NULL��ʾ����ʧ��
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
*@brief:���
*@param:queue ����ָ�� data ��ӵ�����
*@return:����OK��ʾ�ɹ� ERROR��ʾʧ��
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
*@brief:����
*@param:queue ����ָ�� data ���ӵ�����
*@return: NULL��ʾʧ�� �ɹ����س��ӵ�����ָ��
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
*@brief:�ж϶����Ƿ�Ϊ��
*@param:queue ����ָ��
*@return:����OK��ʾΪ�� NO��ʾ��Ϊ��,ERROR��ʾʧ��
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
*@brief:��ȡ���д�С
*@param:queue ����ָ��
*@return:���ض��д�С ERROR��ʾʧ��
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
*@brief:���ٶ���
*@param:queue ����ָ��
*@return:��
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
*@brief:��������
*@param:queue ����ָ��
*@return:��
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