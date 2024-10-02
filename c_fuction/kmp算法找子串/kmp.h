#ifndef _KMP_H
#define _KMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{
   OK=1,
   ERROR=-1,
   NO=0
};

int kmp(char *text, char *pattern,int len,int len1);

#endif // _KMP_H