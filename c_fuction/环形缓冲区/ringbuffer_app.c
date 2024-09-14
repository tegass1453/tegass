#include "ringbuffer_app.h"
/**
 * @brief  对环形缓冲区进行初始化
 * @param  buffer    要初始化的环形缓冲区地址
 * @retval None
 * 示例用法:
 * @code
 * ringbuff buffer_name;
 * ringbuff_init(&buffer_name);
 * @endcode
 */
void ringbuff_init(ringbuff* buffer)
{
    buffer->item_count=0;
    buffer->r=0;
    buffer->w=1;
    memset(buffer->buff,0,sizeof(buffer->buff));
}

/**
 * @brief  判断环形缓冲区是否为空
 * @param  buffer    要判断的环形缓冲区地址
 * @retval 1-缓冲区为空，0-缓冲区非空
 */
unsigned char ringbuff_is_empty(ringbuff* buffer)
{
    return (buffer->item_count==0);
}
/**
 * @brief  判断环形缓冲区是否为满
 * @param  buffer    要判断的环形缓冲区地址
 * @retval 1-缓冲区为满，0-缓冲区非满
 */
unsigned char ringbuff_is_full(ringbuff* buffer)
{
    return (buffer->item_count==RINGBUFF_SIZE);
}
/**
 * @brief  对环形缓冲区写入数据
 * @param  buffer    要写入的环形缓冲区地址
 * @param  dat    要写入的数据
 * @param  num    要写入的数据大小
 * @retval 1-缓冲区写入成功，0-缓冲区写入失败
 * 示例用法:
 * @code
 * ringbuff_init(&buffer_name,&dat,sizeof(dat));
 * @endcode
 */
unsigned char ringbuff_write(ringbuff* buffer,unsigned char* dat,unsigned char num)
{
    for (unsigned char i = 0; i < num; i++)
    {
        if(ringbuff_is_full(buffer))
            return 0;
        else if(buffer->w==RINGBUFF_SIZE)
            buffer->w=0;
        buffer->buff[(buffer->w)++]=*(dat++);
        buffer->item_count++;
    }
    return 1;
}
/**
 * @brief  读取环形缓冲区数据
 * @param  buffer    要读取的环形缓冲区地址
 * @param  dat_reciver    读取的数据赋值处
 * @param  num    要读取的数据大小
 * @retval 1-缓冲区读取成功，0-缓冲区读取失败
 */
unsigned char ringbuff_read(ringbuff* buffer,unsigned char* dat_reciver,unsigned char num)
{
    for (unsigned char i = 0; i < num; i++)
    {
        if(ringbuff_is_empty(buffer))
            return 0;
        else if(buffer->r==255)
            buffer->r=RINGBUFF_SIZE;
        *(dat_reciver++)=buffer->buff[(buffer->r)--];
        buffer->item_count--;
    }
    return 1;
}
