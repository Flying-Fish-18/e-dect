#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "cli.h"
int main(int argc, char const *argv[])
{
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0)
        PRINT_ERR("socket", -1);

    if (connectaddr(sfd) < 0)
        PRINT("connect error\n", -1);

    system("clear");
    char buff[100] = "";
    while (1)
    {
        switch (menu())
        {
            case 1: 
                system("clear");
                do_register(sfd);
                break;
            case 2:
                system("clear");
                if(1 == do_login(sfd))
                    option(sfd);
                break;
            case 3:
                close(sfd);
                return 0;
                break;
            default:
                printf("程序出错\n");
                getchar();
                system("clear");
        }
    }
    close(sfd);
    return 0;
}