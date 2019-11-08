#include <stdio.h>
#include <stdlib.h>

#define MAXBUF          1024

// 提示用户输入一行字符串，最大长度为 nmax，并返回字符串的长度
int my_getline(char line[], int nmax)
{
    int len;
    char c;
    len = 0;
    printf("Enter a string [CR to exit]: ");
    while(((c=getchar())!='\n') && len<nmax-1)
        line[len++]=c;
    line[len]='\0';
    return len;
}

int main(void){
    int ret = -1;
    int len;
    char buffer[MAXBUF];
    char *ptr = NULL;
    int check_result = 0;
    while(1){
        len = my_getline(buffer, MAXBUF);
        if (len==0) break;
        printf("len = %d, line = %s\n", len, buffer);
        ptr = buffer;
        while('\0' != *ptr)
        {
            if('0' > *ptr || '9' < *ptr)
            {
                printf("input error.");
                check_result = -1;
                break;
            }
            ptr++;
        }
        
        if(-1 == check_result)
        {
            check_result = 0;
            continue;
        }

        ret = atoi(buffer);
        printf("ret is %d\n", ret);
    };
}


