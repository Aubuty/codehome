//程序主入口
#include"InputCommand.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "contrlDevices.h"
#include <pthread.h>
#include<unistd.h>
#include <signal.h>
#define BUTTON 7
struct Devices* pDevicesHand = NULL ; 
struct InputCommand* pCommandHand = NULL ; 
struct InputCommand* socket_Handler = NULL; 
int c_fd[3];

struct Devices *findByDevicesName(char *str,struct Devices *phand)
{
    struct Devices *tmp = phand; 
    if(phand == NULL){
        return NULL;
    }else{
        while(tmp != NULL)
        {
            if(strcmp(tmp->DevicesName,str) == 0){
                return tmp; 
            }
            tmp = tmp->next;
        }
        return NULL; 
    }
}

struct InputCommand *findByCommandName(char *str,struct InputCommand *phand)
{
    struct InputCommand *tmp = phand; 
    if(phand == NULL){
        return NULL;
    }else{
        while(tmp != NULL)
        {
            if(strcmp(tmp->CommandName,str) == 0){
                return tmp; 
            }
            tmp = tmp->next;
        }
        return NULL; 
    }
}
void *voice_thread(void* datas)
{
    struct InputCommand* voice_Handler; 
    struct Devices *tmp = NULL;
    int n_read;
    int cmd;
    voice_Handler = findByCommandName("voice",pCommandHand);
    if(voice_Handler == NULL){
        printf("find voice erro\n");
        pthread_exit(NULL);
    }else{
        if(voice_Handler->Init(voice_Handler,NULL,NULL) < -1){
            printf("creat void erron\n");
            pthread_exit(NULL);
        }else{
            printf("%s is init \n",voice_Handler->CommandName);
        }
        while (1)
        {
            n_read = voice_Handler->getCommand(voice_Handler);
            if(n_read <= 0 ){
                printf("voice no data\n");
            }else{
                //printf("voice command is %s\n",voice_Handler->command);
                cmd  = atoi(voice_Handler->command);
                switch (cmd)
                {
                case 11:
                    tmp = findByDevicesName("bathroomLight",pDevicesHand);
                    tmp->DevicesInit(tmp->pinNum);
                    tmp->open(tmp->pinNum);
                    printf("1号灯打开/n");
                    break;
                case 21:
                    tmp = findByDevicesName("livingroomLight",pDevicesHand);
                    tmp->DevicesInit(tmp->pinNum);
                    tmp->open(tmp->pinNum);
                    printf("2号灯打开/n");
                    break;
                case 31:
                    tmp = findByDevicesName("restaurantLight",pDevicesHand);
                    tmp->DevicesInit(tmp->pinNum);
                    tmp->open(tmp->pinNum);
                    printf("3号灯打开/n");
                    break;
                // case 41:
                //     tmp = findByDevicesName("upstairLight",pDevicesHand);
                //     tmp->DevicesInit(tmp->pinNum);
                //     tmp->open(tmp->pinNum);
                //     break;
                case 10:
                    tmp = findByDevicesName("bathroomLight",pDevicesHand);
                    tmp->DevicesInit(tmp->pinNum);
                    tmp->close(tmp->pinNum);
                    printf("1号灯关闭/n");
                    break;
                case 20:
                    tmp = findByDevicesName("livingroomLight",pDevicesHand);
                    tmp->DevicesInit(tmp->pinNum);
                    tmp->close(tmp->pinNum);
                    printf("2号灯关闭/n");
                    break;
                case 30:
                    tmp = findByDevicesName("restaurantLight",pDevicesHand);
                    tmp->DevicesInit(tmp->pinNum);
                    tmp->close(tmp->pinNum);
                    printf("3号灯关闭/n");
                    break;
                // case 40:
                //     tmp = findByDevicesName("upstairLight",pDevicesHand);
                //     tmp->DevicesInit(tmp->pinNum);
                //     tmp->close(tmp->pinNum);
                //     break;
                case 0:
                    closeALL();
                    printf("全部关闭/n");
                    break;
                case 1:
                    OpenALL();
                    printf("全部开启/n");
                    break;
                }
                memset(voice_Handler->command,'\0',sizeof(voice_Handler->command));
            }
        }
    }
}
int ret;     //设置一个用来存储线程func1和func2线程是否创建成功的返回值
int i =0;    // 设置socket
struct sockaddr_in c_addr;
void *read_thread(void* datas){
    struct Devices *tmp = NULL;
    int n_read;
    //printf("%d\n",c_fd);
    memset(socket_Handler->command,'\0',sizeof(socket_Handler->command));
    while (1)
    {
         n_read = read(c_fd[1],socket_Handler->command,sizeof(socket_Handler->command));  
    if(n_read == -1 ){
        perror("read");
    }else if(n_read > 0){
        printf("socket command size is %d data is %s\n",n_read,socket_Handler->command);
        //
    }else
    {
        //printf("client quit\n");
    }
    switch (atoi(socket_Handler->command))
                {
                case 11:
                    tmp = findByDevicesName("bathroomLight",pDevicesHand);
                    tmp->DevicesInit(tmp->pinNum);
                    tmp->open(tmp->pinNum);
                    printf("1号灯打开/n");
                    break;
                case 21:
                    tmp = findByDevicesName("livingroomLight",pDevicesHand);
                    tmp->DevicesInit(tmp->pinNum);
                    tmp->open(tmp->pinNum);
                    printf("2号灯打开/n");
                    break;
                case 31:
                    tmp = findByDevicesName("restaurantLight",pDevicesHand);
                    tmp->DevicesInit(tmp->pinNum);
                    tmp->open(tmp->pinNum);
                    printf("3号灯打开/n");
                    break;
                // case 41:
                //     tmp = findByDevicesName("upstairLight",pDevicesHand);
                //     tmp->DevicesInit(tmp->pinNum);
                //     tmp->open(tmp->pinNum);
                //     break;
                case 10:
                    tmp = findByDevicesName("bathroomLight",pDevicesHand);
                    tmp->DevicesInit(tmp->pinNum);
                    tmp->close(tmp->pinNum);
                    printf("1号灯关闭/n");
                    break;
                case 20:
                    tmp = findByDevicesName("livingroomLight",pDevicesHand);
                    tmp->DevicesInit(tmp->pinNum);
                    tmp->close(tmp->pinNum);
                    printf("2号灯关闭/n");
                    break;
                case 30:
                    tmp = findByDevicesName("restaurantLight",pDevicesHand);
                    tmp->DevicesInit(tmp->pinNum);
                    tmp->close(tmp->pinNum);
                    printf("3号灯关闭/n");
                    break;
                // case 40:
                //     tmp = findByDevicesName("upstairLight",pDevicesHand);
                //     tmp->DevicesInit(tmp->pinNum);
                //     tmp->close(tmp->pinNum);
                //     printf("1号灯关闭/n");
                //     break;
                case 0:
                    closeALL();
                    printf("全部关闭/n");
                    break;
                case 1:
                    OpenALL();
                    printf("全部打开/n");
                    break;
                }
                memset(socket_Handler->command,'\0',sizeof(socket_Handler->command));
    }
}
void *socket_thread(void* datas)
{
    pthread_t t1;
    pthread_t t2;
    pthread_t readpthread;
    int n_read = 0 ;
    memset(&c_addr,0,sizeof(struct sockaddr_in));
    int clen = sizeof(struct sockaddr_in);
    socket_Handler = findByCommandName("socketSever",pCommandHand);
    if(socket_Handler == NULL){
        printf("find socket erro\n");
        pthread_exit(NULL);
    }else{
        printf("%s init success\n",socket_Handler->CommandName);
    }
    socket_Handler->Init(socket_Handler,NULL,NULL);
    
    while (1)
    {
                  
            c_fd[1] =accept(socket_Handler->sfd,(struct sockaddr *)&c_addr,&clen); 
            ret =pthread_create(&t1,NULL,read_thread,NULL);    //创建thread1线程
                       
    }
}
void *Threadfire(void *arg)
{
    int fd1;
    struct Devices *tmp = NULL;
    char buf[8];
    tmp = findByDevicesName("fileifOrnot",pDevicesHand); 
    tmp->DevicesInit(tmp->pinNum);
    fd1 = open("./file.txt",O_WRONLY|O_CREAT,0777);
    if (fd1 < 0)
	{
		perror("open file failed");
    }else{
        printf("检测开启\n");
    }
    int Testnum=0;
    while (1)
    {
        buf[8] = tmp->readstatus(tmp->pinNum);
        if(write(fd1,buf,strlen(buf)) < 0)
		{
			perror("write failed");
			pthread_exit(NULL);
		}else{
            printf("当前状态:%d\n",Testnum++);
        }
        delay(1000);
    }
    
}
void *ThreadFun(void *arg)
{
    // int res;
    // struct Devices *tmp = NULL;
    //  char ficecmd[127]={'\0'};
    // chdir("/home/pi/mjpg-streamer/mjpg-streamer-experimental");
    // system("nohup ./mjpg_streamer -i \"./input_raspicam.so\" -o \"./output_http.so -w ./www\" > came.file 2>&1 &");
    // pinMode(BUTTON, INPUT);
    // pullUpDnControl(BUTTON, PUD_UP);
    // tmp = findByDevicesName("look",pDevicesHand); 
    // tmp->DevicesInit(tmp->pinNum);
    // tmp->status = 0 ; 
    // while(1)
    // {
    //     if(digitalRead(BUTTON) == LOW)
    //     {
    //         delay(5);
    //         if(digitalRead(BUTTON) == LOW)
    //         {
    //                 sprintf(ficecmd,"wget  http://192.168.137.100:8080/?action=snapshot -O /home/pi/smartHost/picture/imeag.jpg  >/dev/null 2>&1");
    //                 system(ficecmd);
    //                 if(tmp->status == 1){
    //                     tmp->close(tmp->pinNum); 
    //                     tmp->status = 0; 
    //                 }else{
    //                     res = postUrl();
    //                     if(res == 1 && tmp->status == 0){
    //                         tmp->open(tmp->pinNum);
    //                         tmp->status = 1; 
    //                     }
    //                 } 
    //         }
    //     }
    //     delay(100);
    // } 
}


int main()
{
    pthread_t voicepthread;
    pthread_t socketpthread;
    pthread_t cameThread1;
    pthread_t fireThread;
    struct Devices* tmp; 
    char Buf[128] ;
    if(wiringPiSetup() == -1){
        return -1;
    }

    pininit();
    //指令工厂初始
    pCommandHand = addvoiceContlToinputCommadnLink(pCommandHand);
    pCommandHand = addsocketContlToinputCommadnLink(pCommandHand);
    //设备工厂初始
    pDevicesHand = addBathroomLightToDevicesLink(pDevicesHand); 
    pDevicesHand = addupstairLightToDevicesLink(pDevicesHand);
    pDevicesHand = addlivingroomLightToDevicesLink(pDevicesHand);
    pDevicesHand = addrestaurantLightToDevicesLink(pDevicesHand);
    pDevicesHand = addfirestatusToDevicesLink(pDevicesHand);
    pDevicesHand = addlookToDevicesLink(pDevicesHand);
       //线程池 int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_rtn)(void *), void *restrict arg);
        //语音线程
    pthread_create(&voicepthread,NULL,voice_thread,NULL);
    // //     //socket线程
    //pthread_create(&socketpthread,NULL,socket_thread,NULL);
    // //     //摄像头线程
     pthread_create(&cameThread1, NULL, ThreadFun, NULL);
    // //     //火灾线程
     pthread_create(&fireThread,NULL,Threadfire,NULL);
    // while (1)
    // {
    //     printf("input : "); 
    //     scanf("%s",Buf); 
    //     getchar();
    //     if(strcmp(Buf,"-1") == 0){
    //         pininit();
    //         exit(-1);
    //     }
    //     tmp = findByDevicesName(Buf,pDevicesHand); 
    //     if(tmp != NULL){
    //         tmp->DevicesInit(tmp->pinNum);
    //         tmp->open(tmp->pinNum);
    //     }
    //     memset(Buf,'\0',sizeof(128));
    // }
    pthread_join(voicepthread,NULL);
    pthread_join(socketpthread,NULL);
    pthread_join(cameThread1,NULL);
    pthread_join(fireThread,NULL);
}