/*************************************************************************
	> File Name: tcp_client.c
	> Author: liulianglu
	> Description: 
	> Created Time: Wed 15 Apr 2015 10:18:50 AM EDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/errno.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include<unistd.h>

int main(int argc, char *argv[])
{
    int iMsgSize    = 1024;
    char* strIP     = "192.168.66.66";
    int iPort       = 6666;

    if(argc > 1)
    {
        iMsgSize = atoi(argv[1]);
    }
    if(argc > 3)
    {
        strIP = argv[2];
        iPort = atoi(argv[3]);
    }

    char* szMsg = (char*)malloc(sizeof(char*) * iMsgSize);
    memset(szMsg, 0x66, iMsgSize);

    struct sockaddr_in server;
    memset(&server, 0x00, sizeof(server));

    server.sin_family   = AF_INET;
    server.sin_port     = htons(iPort);
    inet_pton(AF_INET, strIP, &server.sin_addr);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("Create socket error: %d", errno);
        exit(0);
    }
    if(connect(sockfd, (struct sockaddr*) &server, sizeof(server)) < 0)
    {
        printf("Connect server error: %d", errno);
        exit(0);
    }


    int iTransport = write(sockfd, szMsg, iMsgSize);

    printf("send %d \n", iTransport);

    iTransport = read(sockfd, szMsg, iMsgSize);

    printf("recieve %d \n", iTransport);


    return 0;




}
