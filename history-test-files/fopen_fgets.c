#include <stdio.h> 
#define MAX_LINE 1024                   //每行最大字节数
 
int main() 
{ 
    FILE *fp; 
    char strLine[MAX_LINE];                             //读取缓冲区
    if((fp = fopen("testaaa","r")) == NULL)      //判断文件是否存在及可读
    { 
        printf("Open Falied!"); 
        return -1; 
    } 
    while (!feof(fp))                                   //循环读取每一行，直到文件尾
    { 
        fgets(strLine,MAX_LINE,fp);                     //将fp所指向的文件一行内容读到strLine缓冲区
        printf("%s", strLine);                          //输出所读到的内容
        if(0 == strncmp("efs", strLine, strlen("efs")))
        {
            printf("good\n");
        }
             //DO SOMETHING ELSE
    } 
    fclose(fp);                                         //关闭文件
    printf("\n");
   return 0; 
}

