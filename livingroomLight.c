//客厅灯  livingroomLight
#include"contrlDevices.h"
int livingroomLightopen(int pinNum)//on
{
    digitalWrite(pinNum,LOW);
}   
int livingroomLightclose(int pinNum)//off
{
    digitalWrite(pinNum,HIGH);

}
int livingroomLightInit(int pinNum)//init
{
    pinMode(pinNum,OUTPUT); 
    digitalWrite(pinNum,HIGH); 

}
int livingroomLightclosechange(int status)
{

}
struct Devices livingroomLight={
    .open = livingroomLightopen,
    .close = livingroomLightclose,
    .DevicesName = "livingroomLight",
    .DevicesInit = livingroomLightInit,
    .pinNum = 23,
    .changestatus = livingroomLightclosechange

};
struct Devices* addlivingroomLightToDevicesLink(struct Devices* phand)
{
    printf("添加%s\n",livingroomLight.DevicesName);
    if(phand == NULL){
        return &livingroomLight;
    }else{
        livingroomLight.next = phand;
        phand = &livingroomLight;
        return phand;
    }
}