#include <stdio.h>

static int Check_ProcessIsRun(char *proc)
{
    FILE* fp = NULL; 
    unsigned char   count = 1; 
    int BUFSZ = 2; 
    char buf[BUFSZ]; 
    char command[128]; 
 
    sprintf(command, "ps | grep -w %s | wc -l", proc); 

    if((fp = popen(command,"r")) == NULL) 
    { 
        printf("popen err\r\n");
        return -1;
    } 
    
    memset(buf,0,sizeof(BUFSZ));
    if((fgets(buf,BUFSZ,fp))!= NULL) 
    { 
        printf("####buf=%s \n",buf);
        count = atoi(buf); 
    } 
    
    pclose(fp); 
    
    fp=NULL; 
    
    printf("====count=%d\n",count);
    if ((count -1) == 0) {
        return -1;
    } else {
        return 0;
    }
}

int main()
{
    int ret = Check_ProcessIsRun("test");
    printf("ret is %d\n", ret);
    return 0;
}

