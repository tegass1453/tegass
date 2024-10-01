#include  "SeqList.h"

/*
*@function:创建顺序表
*@param:max_size:顺序表的最大容量
*@return:返回顺序表指针 NULL:创建失败
*/
SeqList* SeqList_create(int max_size) //创建顺序表
{
    SeqList* temp=(SeqList*)malloc(sizeof(SeqList));
    if(temp==NULL)
    {
        fprintf(stderr,"SeqListheadzone malloc error \n");
        return NULL;
    }

    temp->data=(seqlist_data_t*)malloc(sizeof(seqlist_data_t)*max_size);
    if(temp->data==NULL)
    {
        free(temp);
        fprintf(stderr,"SeqListdatazone malloc error \n");
        return NULL;
    }

    memset(temp->data,0,sizeof(seqlist_data_t)*max_size);

    temp->data_num=0;
    temp->max_size=max_size;

    return temp;
}

/*
*@function:插入顺序表
*@param:pos:插入位置 value:插入的值 list:顺序表指针
*@return:0:插入成功 -1:插入失败
*/
int SeqList_insert(SeqList *list, int pos, seqlist_data_t value) //插入元素
{
    int temp =0;
    if(list==NULL)
    {
        fprintf(stderr,"SeqList is NULL\n");
        return -1;
    }

    if(pos<0||pos>list->data_num)
    {
        fprintf(stderr,"pos is error\n");
        return -1;
    }

    if(list->data_num==list->max_size)
    {
        fprintf(stderr,"SeqList is full\n");
        return -1;
    }


    for (temp = list->max_size-1; temp>pos; temp--)
    {
        list->data[temp]=list->data[temp-1];
    }

    list->data[pos]=value;
    list->data_num++;
    return 0;
    
}

/*
*@function:删除顺序表
*@param:pos:删除位置 list:顺序表指针
*@return:0:删除成功 -1:删除失败
*/
int SeqList_delete(SeqList *list, int pos)
{
    int temp = 0;
     if(list==NULL)
    {
        fprintf(stderr,"SeqList is NULL\n");
        return -1;
    }

    if(pos<0||pos>list->data_num)
    {
        fprintf(stderr,"pos is error\n");
        return -1;
    }

    for (temp = pos; temp<list->max_size; temp++)
    {
        list->data[temp]=list->data[temp+1];
    }

    list->data_num--;

    return 0;
}


/*
*@function:查找顺序表
*@param:value:查找元素 list:顺序表指针
*@return:0:查找成功 -1:查找失败
*/
int SeqList_find(SeqList *list, seqlist_data_t value)
{
    int temp =0;
    for (temp =0; temp<list->max_size; temp++)
    {
        /*若value为float，double，struct,union等类型，以下代码需更改*/
        /*user code start*/
        if(list->data[temp] == value)
        {
            return temp;
        }
        /*user code end*/
    }

    return -1;
}

/*
*@function:打印顺序表
*@param:list:顺序表指针
*@return:无
*@attention :需要用户补充代码
*/
void SeqList_print(SeqList *list)
{
    int temp =0;
    for (temp =0; temp<list->data_num; temp++)
    {
        /*user code start*/

        /*user code end*/
    }

}
/*
*@function:销毁顺序表
*@param:list:顺序表指针
*@return:无
*/
void SeqList_destroy(SeqList *list)
{
    if(list==NULL)
    {
        return;
    }

    free(list->data);
    free(list);
    list = NULL;
}

/*
*@function:更新顺序表
*@param:list:顺序表指针 pos:要更新的位置 value:要更新的值
*@return:0:更新成功 -1:更新失败
*/
int SeqList_update(SeqList *list, int pos, seqlist_data_t value)
{
    if(list==NULL)
    {
        fprintf(stderr,"SeqList is NULL\n");
        return -1;
    }

    if(pos<0||pos>list->data_num)
    {
        fprintf(stderr,"pos is error\n");
        return -1;
    }

    list->data[pos]=value;

    return 0;

}

/*
*@function:获取顺序表的值
*@param:list:顺序表指针 value:要获取的值存放位置 pos:要获取的位置
*@return:0:获取成功 -1:获取失败
*/
int SeqList_get(SeqList *list, int pos, seqlist_data_t *value)
{
    if(list==NULL)
    {
        fprintf(stderr,"SeqList is NULL\n");
        return -1;
    }

    if(pos<0||pos>list->data_num)
    {
        fprintf(stderr,"pos is error\n");
        return -1;
    }

    *value=list->data[pos];
    return 0;
}


/*
*@function:获取顺序表的长度、
*@param:list:顺序表指针
*@return:顺序表的长度
*/
int SeqList_length(SeqList *list)
{
    if(list==NULL)
    {
        fprintf(stderr,"SeqList is NULL\n");
        return -1;
    }

    return list->data_num;
}

/*
*@function:判断顺序表是否为空
*@param:list:顺序表指针
*@return:1:为空 0:不为空 -1:错误
*/
int SeqList_is_empty(SeqList *list)
{
    if(list==NULL)
    {
        fprintf(stderr,"SeqList is NULL\n");
        return -1;
    }

    if(list->data_num==0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }

}

/*
*@function:判断顺序表是否已满
*@param:list:顺序表指针
*@return:1:已满 0:未满 -1:错误
*/
int SeqList_is_full(SeqList *list)
{
    if(list==NULL)
    {
        fprintf(stderr,"SeqList is NULL\n");
        return -1;
    }

    if(list->data_num==list->max_size)
    {
        return 1;
    }
    else 
    {
        return 0;
    }

}

/*
*@function:清空顺序表
*@param:list:顺序表指针
*@return:0:成功 -1:错误
*/
int SeqList_clear(SeqList *list)
{
     if(list==NULL)
    {
        fprintf(stderr,"SeqList is NULL\n");
        return -1;
    }
    
    list->data_num=0;
    return 0;
}