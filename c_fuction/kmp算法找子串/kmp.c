#include "kmp.h"

/*
*@brief:��ȡ��һ�αȶ�λ�õ�λ����������
*@param:pattern:ģʽ�� next_num:�洢λ�����ݵ����� len:ģʽ������
*@return:��
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
*@brief:KMP�㷨������ı������Ƿ����ģʽ��
*@param:text:�ı��� pattern:ģʽ�� len:�ı������� len1:ģʽ������
*@return:ƥ��ɹ�����OK,ƥ��ʧ�ܷ���NO
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