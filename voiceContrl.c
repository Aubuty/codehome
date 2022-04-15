//语音
#include<stdio.h>
#include<wiringSerial.h>
#include"InputCommand.h"
#include<wiringPi.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
// struct InputCommand
// {
//     char CommandName[128];//名字
//     char command[32]; //指令
//     int (*Init)(char *name,char*ipAdress,char *port);//操作函数
//     int (*getCommand)(char *cmd);//获得数据 存放到command中 返回执行状态
//     char log[1024];//日志
//     struct InputCommand *next;
// };
int voiceGetCommand(struct InputCommand *voicer);
int voiceInit(struct InputCommand *voicer,char*ipAdress,char *port)
{
    int fd; 
    if((fd = serialOpen(voicer->deviceName,9600))==-1)    //初始化串口，波特率9600  
    {
        printf("123");
        exit(-1);
    }
   voicer->voicefd = fd; 
    return fd;
}
int voiceGetCommand(struct InputCommand *voicer)
{
    int nread = 0;
    nread = read(voicer->voicefd,voicer->command,sizeof(voicer->command));
    return nread;
}
struct InputCommand voiceContl = {
        .CommandName = "voice", 
        .command = '\0', 
        .Init = voiceInit, 
        .deviceName = "/dev/ttyAMA0",
        .getCommand = voiceGetCommand,
        .log = {'\0'},
        .next = NULL
};
struct InputCommand* addvoiceContlToinputCommadnLink(struct InputCommand *phand)
{
    if(phand == NULL){
        return &voiceContl;
    }else{
        voiceContl.next = phand;
        phand = &voiceContl;
        return phand;
    }
}
