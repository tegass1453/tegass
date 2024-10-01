#ifndef _SEQLIST_H 
#define _SEQLIST_H 

#include "string.h"
#include <stdio.h>
#include <stdlib.h>
 
/* 顺序表数据类型 */
typedef int seqlist_data_t;

typedef struct 
{
    seqlist_data_t *data;    //数据区
    int data_num;       //目前数据数量
    int max_size;   //最大容量

} SeqList;


void SeqList_print(SeqList *list);   //打印
/* 上述函数需要用户补充代码 */
int SeqList_is_empty(SeqList *list); //判断是否为空
int SeqList_is_full(SeqList *list); //判断是否已满
SeqList* SeqList_create(int max_size); //创建
int SeqList_insert(SeqList *list, int pos, seqlist_data_t value); //插入 
int SeqList_delete(SeqList *list, int pos); //删除
int SeqList_find(SeqList *list, seqlist_data_t value); //查找
void SeqList_destroy(SeqList *list); //销毁 
int SeqList_update(SeqList *list, int pos, seqlist_data_t value); //更新
int SeqList_get(SeqList *list, int pos, seqlist_data_t *value); //获取
int SeqList_length(SeqList *list); //获取当前长度 
int SeqList_is_empty(SeqList *list); //判断是否为空
int SeqList_is_full(SeqList *list); //判断是否已满
int SeqList_clear(SeqList *list); //清空

#endif
