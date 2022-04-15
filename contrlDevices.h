//控制设备
#include<stdio.h>
#include<wiringPi.h>
#define true 1 ;
#define false 0 ;
typedef unsigned int bool;
struct Devices
{
    char DevicesName[128];//设备名字
    int status;//开关状态
    int pinNum;//端口
    int (*open)(int pinNum);//开
    int (*close)(int pinNum);//关
    int (*DevicesInit)(int pinNum);//设备初始化
    int (*readstatus)(int pinNum);//读取状态
    int (*changestatus)(int status);//改变状态
    struct Devices *next;
    /* data */
};
struct Devices* addBathroomLightToDevicesLink(struct Devices* phand); //卫生间灯
struct Devices* addupstairLightToDevicesLink(struct Devices* phand);//
struct Devices* addlivingroomLightToDevicesLink(struct Devices* phand);
struct Devices* addrestaurantLightToDevicesLink(struct Devices* phand);
struct Devices* addfirestatusToDevicesLink(struct Devices* phand);
struct Devices* addlookToDevicesLink(struct Devices* phand);
void pininit();
int postUrl();
void closeALL();
void OpenALL();
