#include <stdio.h>
#include <signal.h>

void signal_handler(int signal)
{
    printf("Received signal %d\n", signal);
    printf("do something...\n");
    return;
}

int main(int argc, char *argv[])
{
    signal(SIGHUP, signal_handler);
    while(1)
    {
        sleep(2000);
    }
    return 0;
}