#include<stdio.h>
#include <pthread.h>

static void mythreadfun( void *arg )
{
    /*这将该子线程的状态设置为detached,则该线程运行结束后会自动释放所有资源*/
    pthread_detach(pthread_self());
    printf("arg is %s\n", (char *)arg);

    int i = 0;
    while(1)
    {
        printf("do something...\n");
        if(i++ == 10)
        {
            break;
        }
        sleep(2);
    }

    return ;
}

int main(int argc, char *argv[])
{
    pthread_t pthreadid = 0;
    int ret = 0;
    char *param = "good";
    
    /* 创建线程 */
    ret = pthread_create(&pthreadid, NULL, (void *)mythreadfun, (void *)param);
    if(ret != 0)
    {
        printf("create pthread failed.");
        return;
    }
    
    printf("create pthread success.");
    while(1)
    {
        sleep(2000);
    }
    
    return 0;
}