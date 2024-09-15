#ifndef _RINGBUFFER_APP
#define _RINGBUFFER_APP

#include "string.h"

/*环形缓冲区大小设定*/
#define RINGBUFF_SIZE 30

/*环形缓冲区结构*/
typedef struct 
{
    unsigned char w;
    unsigned char r;
    unsigned char buff[RINGBUFF_SIZE];
    unsigned char item_count;
}ringbuff;

/*环形缓冲区函数*/
void ringbuff_init(ringbuff* p);
unsigned char ringbuff_is_empty(ringbuff* p);
unsigned char ringbuff_is_full(ringbuff* p);
unsigned char ringbuff_write(ringbuff* p,unsigned char* dat,unsigned char num);
unsigned char ringbuff_read(ringbuff* p,unsigned char* dat_reciver,unsigned char num);

#endif
