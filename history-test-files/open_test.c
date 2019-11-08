#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

void write_data_to_file(char *data, int data_len)
{
    if(NULL == data || data_len < 0)
    {
        printf("input param invalid\n");
        return;
    }

    int fd = -1;
    int rcode = 0;
    fd = open("partitionsfiles", O_CREAT | O_RDWR);
    if(fd < 0)
    {   
        printf("open failed\n");
        goto error;
    }

    rcode = write(fd, data, data_len);
    if(rcode != data_len)
    {
        printf("write error\n");
        goto error;
    }
    
    printf("write success\n");
    fsync(fd);
    close(fd);
    return ;

error:
    if(fd >= 0)
        close(fd);
    return ;
}

int main()
{
    
    write_data_to_file("AABB", strlen("AABB"));
    return 0;
}

