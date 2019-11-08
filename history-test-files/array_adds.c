#include <stdio.h>

int main()
{
    int array[10] = {0};
    array[0] = 100;
    int *ptr1 = NULL;
    int *ptr2 = NULL;
    ptr1 = array;
    ptr2 = (int *)&array[0];
    printf("array is %p\n", array);
    printf("array + 1 is %p\n", array + 1);
    printf("array[0] is %p\n", (int *)&array[0]);
    printf("array + 1 %p\n", ptr1 + 1);
    printf("array[0] + 1 %p\n", ptr2 + 1);
    return 0;
}

