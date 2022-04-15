//语音
#include<stdio.h>
#include<wiringSerial.h>
#include"InputCommand.h"
#include<wiringPi.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

// struct InputCommand
// {
//     char CommandName[128];//名字
//     char command[32]; //指令
//     int (*Init)(char *name,char*ipAdress,char *port);//操作函数
//     int (*getCommand)(char *cmd);//获得数据 存放到command中 返回执行状态
//     char log[1024];//日志
//     struct InputCommand *next;
// };
int socketInit(struct InputCommand *socketMes,char*ipAdress,char *port)
{
    //建立套接字
    int s_fd;
    struct sockaddr_in s_addr;
    memset(&s_addr,0,sizeof(struct sockaddr_in));
    //1.建立socket 
    s_fd = socket(AF_INET,SOCK_STREAM,0);
    if(s_fd == -1){
        perror("socket");
        exit(-1);
    }
    s_addr.sin_family = AF_INET;//协议类型
    s_addr.sin_port = htons(atoi(socketMes->port));//端口类型
    inet_aton(socketMes->ipAddress,&s_addr.sin_addr);//ip 地址
    // 2.绑定 端口 协议 ip地址
    int opt = 1;
    setsockopt(s_fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof( opt ));
    bind(s_fd,(struct sockaddr *)&s_addr,sizeof(struct sockaddr_in));
    //  3.监听
    listen(s_fd,10);
    printf("socket listening_________\n");
    socketMes->sfd = s_fd;
    return s_fd;

}

int socketGetCommand(struct InputCommand *socketMes)
{
    int c_fd;
    struct sockaddr_in c_addr;
    int n_read = 0 ;
    memset(&c_addr,0,sizeof(struct sockaddr_in));
    int clen = sizeof(struct sockaddr_in);
    c_fd = accept(socketMes->sfd,(struct sockaddr *)&c_addr,&clen);
    n_read = read(socketMes->sfd,socketMes->command,sizeof(socketMes->command));
    if(n_read == -1){
        perror("read");
    }else if(n_read > 0){
        printf("nget: %d",n_read); 
    }else{
        //printf("clinet quit");
    }
    return n_read;

}
struct InputCommand socketContl = {
        .CommandName = "socketSever", 
        .command = '\0', 
        .Init = socketInit, 
        .port = "8088",
        .ipAddress = "192.168.3.28",
        .getCommand = socketGetCommand,
        .log = {'\0'},
        .next = NULL
};
struct InputCommand* addsocketContlToinputCommadnLink(struct InputCommand *phand)
{
    if(phand == NULL){
        return &socketContl;
    }else{
        socketContl.next = phand;
        phand = &socketContl;
        return phand;
    }
}
