//锁
#include"contrlDevices.h"
int lookopen(int pinNum)//on
{
    digitalWrite(pinNum,LOW);
}   
int lookclose(int pinNum)//off
{
    digitalWrite(pinNum,HIGH);
}
int looktInit(int pinNum)//init
{
    pinMode(pinNum,OUTPUT); 
    digitalWrite(pinNum,HIGH); 

}

struct Devices look={
    .open = lookopen,
    .close = lookclose,
    .DevicesName = "look",
    .DevicesInit = looktInit,
    .pinNum = 1,
};
struct Devices* addlookToDevicesLink(struct Devices* phand)
{
    printf("添加%s\n",look.DevicesName);
    if(phand == NULL){
        return &look;
    }else{
        look.next = phand;
        phand = &look;
        return phand;
    }
}
