//输入设备  指令工厂
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
struct InputCommand
{
    char CommandName[128];//名字
    char command[32]; //指令
    char deviceName[128];
    int voicefd;
    char port[12];
    char ipAddress[32];
    int sfd;
    //int (*Init)(char *name,char*ipAdress,char *port);//操作函数
    int (*Init)(struct InputCommand *voicer,char*ipAdress,char *port);//操作函数
    int (*getCommand)(struct InputCommand *voicer);//获得数据 存放到command中 返回执行状态
    char log[1024];//日志
    struct InputCommand *next;
};
struct InputCommand* addvoiceContlToinputCommadnLink(struct InputCommand *phand);
struct InputCommand* addsocketContlToinputCommadnLink(struct InputCommand *phand);