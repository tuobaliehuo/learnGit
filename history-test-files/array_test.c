#include <stdio.h>

int main()
{
    char array_a[][10] = 
    {
        "aaaaaaaa",
        "bbbbbbbbb",
    };

    int i = 0;
    printf("len is %d\n", sizeof(array_a)/sizeof(array_a[0]));
    for(i = 0; i < sizeof(array_a)/sizeof(array_a[0]); i++)
    {
        printf("array_a[%d]= %s\n", i, array_a[i]);
    }
    
    return 0;
}

