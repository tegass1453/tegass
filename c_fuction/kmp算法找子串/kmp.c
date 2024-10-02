#include "kmp.h"

/*
*@brief:获取下一次比对位置的位置数据数组
*@param:pattern:模式串 next_num:存储位置数据的数组 len:模式串长度
*@return:无
*/
void next(char *pattern, int *next,int len) 
{
    int i,j;
    i=1;j=0;
    next[0]=0;
    next[1]=0;
    while (i<len)
    {
        if(j==0||pattern[i]==pattern[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}


/*
*@brief:KMP算法，检测文本串中是否存在模式串
*@param:text:文本串 pattern:模式串 len:文本串长度 len1:模式串长度
*@return:匹配成功返回OK,匹配失败返回NO
*/
int kmp(char *text, char *pattern,int len,int len1)
{
    int t=0,x=0;
    int* next_num=(int*)malloc(sizeof(int)*len1);
    next(pattern,next_num,len1);
    while(t<len1&&x<len)
    {
        if(x==0||text[t]==pattern[x])
        {
            t++;
            x++;
        }
        else
        {
            x=next_num[x];
        }
    }
    if(x>=len1)
    {
        return OK;
    }
    else
    {
        return NO;
    }
   
}