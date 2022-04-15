#include<stdio.h>
#include<wiringPi.h>
#include <stdlib.h>
#include<unistd.h>
#include<string.h>
#include<wiringSerial.h>
#define LED 21 
int main()
{
    char buf[128] = {'\0'};
    int fd; //Linux 的思想是：将一切IO设备，都看做 文件，fd就是代表串口抽象出来的文件
    if(-1==wiringPiSetup())
    {
        exit(-1);
    }
    pinMode(LED,OUTPUT); 
    digitalWrite(LED,HIGH); 
    if((fd = serialOpen("/dev/ttyAMA0",9600))==-1)    //初始化串口，波特率9600
    {
        printf("123");
        exit(-1);
    }
   int nrand; 
    while(1)
    {
        nrand = read(fd,buf,sizeof(buf)); 
        if(nrand == 0){
            printf("no datas\n");
        }else
        {
            printf("get : %s\n",buf); 
            memset(buf,'\0',128);
            nrand =0; 
        }
        //printf("%s",buf); 
        
    }
    return 0;
}
