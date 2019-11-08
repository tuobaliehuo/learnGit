#include <stdio.h>
#include <unistd.h>
int main()
{
    char buf[10] = {0};
    int ret = access(buf, F_OK);
    if(ret < 0)
    {
        printf("ret is %d\n",ret);
    }
    else
    {
        printf("ret is %d\n", ret);
    }
    
    return -1;
}

