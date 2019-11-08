#include <stdio.h>
int main(int argc, char *argv[])
{
    char *ptr = NULL;
    printf("argc is %d\n", argc);
    printf("argv0 is %s\n", argv[0]);
    printf("argv1 is %s\n", argv[1]);
    ptr = argv[1];
    ptr = ptr + strlen(argv[1]) - 4;
    if(NULL != argv[1])
    {
        printf("ptr is %s\n", ptr);
        if(0 == strncmp(ptr, ".bin", 4))
        {
            printf("is bin\n");
        }
        else if(0 == strncmp(ptr, ".zip", 4))
        {
            printf("is zip\n");
        }
        else
        {
            printf("package type error.\n");
        }
    }
    
    
    printf("end\n");
    return 0;
}

