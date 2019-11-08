#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#define SERVER_SOCKET_FILE  "/tmp/server_socket"

static void recvfunc( void *arg )
{

    

}

int main()
{
    int ret = 0;
    int retry = 5;
    int i = 0;
    int client_fd = 0;
    struct sockaddr_un server_addr;
    char buff[4096] = {0};
    int  recv_data_len = 0;
    struct sockaddr_un client_addr;
    socklen_t sock_len = sizeof(client_addr);
    if ((client_fd = socket(PF_UNIX, SOCK_STREAM, 0)) < 0)
    {
        printf("create sockfd failed\n");
        return -1;
    }

    printf("update socket create success.\n");

    memset(&server_addr,0x00,sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, SERVER_SOCKET_FILE, strlen(SERVER_SOCKET_FILE));

    for(i = 0; i < retry; i++)
    {
        ret = connect(client_fd,(struct sockaddr*)&server_addr,sizeof(server_addr));
        if(0 != ret)
        {
            printf("cannot connect to the server, retry %d time.\n", i);
            sleep(1);
            continue;
        }
        else
        {
            printf("connect server success.\n");
            break ;
        }
    }
    
    write(client_fd, "hello", strlen("hello"));
    
    while(1)
    {
        memset(buff, 0, sizeof(buff));
        recv_data_len = recvfrom(client_fd, buff, sizeof(buff), 0, (struct sockaddr *)&client_addr, &sock_len);
        if(recv_data_len <= 0)
        {
            sleep(1); //sleep 100ms and receive from socket again
            printf("recv_data_len is %d.\n", recv_data_len);

            /* 重新连接 */
            close(client_fd);
            continue;
        }

        printf("recv data [%s]\n", buff);
        
        /* do something */
        sleep(1);
        write(client_fd, "recv data form server", strlen("recv data form server"));
    }
    return 0;
}

