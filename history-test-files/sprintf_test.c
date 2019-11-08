#include <stdio.h>

int main()
{
#if 0
    char path[128] = "/dasda";
    
    int ret = sprintf(path, "%s","/cache/aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa.bin");
    if(ret < 0)
    {
        printf("sprint fail.%d\n",ret);
    }  
    else
    {
        printf("sprintf success\n");
    } 
    printf("path is %s\n", path);
#endif    
#if 0     
    char *buf2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char buf1[10] = {0};
    int i = 0;    
    char *p = NULL;
    p = strncpy(buf1, buf2, strlen(buf2));
    if(NULL == p)
    {
        printf("strncpy fail.\n");
    }
    else
    {
        printf("strncpy success.\n");
    }
#endif

    char *buf2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char buf1[10] = {0};
    int ret = 0;
    ret = snprintf(buf1, sizeof(buf1), "%s", buf2);
    if(ret < 0)
    {   
        printf("snprintf fail ret is %d\n", ret);
    }
    else
    {
        printf("snprintf success ret is %d\n", ret);
    }       
    
    char buf3[128] = {0};
    ret = sprintf(buf3, "%s", buf2);
    if(ret < 0)
    {   
        printf("sprintf fail ret is %d\n", ret);
    }
    else
    {
        printf("strlen(buf2) is %d\n", strlen(buf2));
        printf("sprintf success ret is %d\n", ret);
        printf("buf3 is %s\n", buf3);
    }       
    
    printf("buf1 is %s\n", buf1);

    char *ptr = NULL;
    memset(buf3, 0x00, sizeof(buf3));
    sprintf(buf3, "%s_%s",  strtok(buf2, "\""), buf2);
    printf("buf3 is %s\n", buf3);

    return 0;
}

