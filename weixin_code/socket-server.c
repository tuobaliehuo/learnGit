#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SERVER_SOCKET_FILE  "/tmp/server_socket"

int main()
{
    int ret = 0;
    int listen_fd = -1;
    int size = 0;
    int conn_fd = -1;
    int max_fd = 0;
    fd_set reads;
    struct sockaddr_un clt_addr;
    socklen_t len = sizeof(clt_addr);
    struct sockaddr_un srv_addr;
    unsigned char buf[4096];

    listen_fd = socket(PF_UNIX, SOCK_STREAM, 0);
    if(listen_fd < 0)
    {
        printf("can not create listen socket\n");
        return -1;
    }

    srv_addr.sun_family = AF_UNIX;
    strncpy(srv_addr.sun_path, SERVER_SOCKET_FILE, sizeof(srv_addr.sun_path));

    unlink(SERVER_SOCKET_FILE);
    ret = bind(listen_fd,(struct sockaddr*)&srv_addr, sizeof(srv_addr));
    if(ret < 0)
    {
        printf("can not bind server socket");
        close(listen_fd);
        return -1;
    }

    ret = listen(listen_fd, 5);
    if(ret < 0)
    {
        printf("can not listen the client");
        close(listen_fd);
        return -1;
    }

    while(1)
    {
        FD_ZERO(&reads);
        FD_SET(listen_fd, &reads);
        max_fd = listen_fd;
        if(conn_fd > 0)
        {
            FD_SET(conn_fd, &reads);
            if(conn_fd > max_fd)
            {
                max_fd = conn_fd;
            }
        }

        ret = select(max_fd+1, &reads, 0, 0, NULL);
        if(ret <= 0)
        {
            perror("select fail\n");
            return -1;
        }
        else
        {
            memset(buf, 0, sizeof(buf));
            if(FD_ISSET(listen_fd, &reads))
            {
                conn_fd = accept(listen_fd, (struct sockaddr*)&clt_addr, &len);
                if(conn_fd <= 0)
                {
                    perror("can not accept socket\n");
                }
                else
                {
                    printf("new connect,conn_fd:%d\n", conn_fd);
                }
            }

            if(FD_ISSET(conn_fd, &reads))
            {
                printf("recv client msg,conn_fd:%d\n",conn_fd);
                size = read(conn_fd, buf, sizeof(buf));
                if(size > 0)
                {
                    printf("get %d socket data is %s\n", size, buf);
                }
                else
                {
                    close(conn_fd);
                    conn_fd = -1;
                }
                sleep(3);
                write(conn_fd, "i am server", strlen("i am server"));                
            }
        }
    }
}
