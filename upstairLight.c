//二楼灯
#include"contrlDevices.h"
int upstairLightopen(int pinNum)//on
{
    digitalWrite(pinNum,LOW);
}   
int upstairLightclose(int pinNum)//off
{
    digitalWrite(pinNum,HIGH);

}
int upstairLightInit(int pinNum)//init
{
    pinMode(pinNum,OUTPUT); 
    digitalWrite(pinNum,HIGH); 

}
int upstairLightclosechange(int status)
{

}
struct Devices upstairLight={
    .open = upstairLightopen,
    .close = upstairLightclose,
    .DevicesName = "upstairLight",
    .DevicesInit = upstairLightInit,
    .pinNum = 22,
    .changestatus = upstairLightclosechange

};
struct Devices* addupstairLightToDevicesLink(struct Devices* phand)
{
    printf("添加%s\n",upstairLight.DevicesName);
    if(phand == NULL){
        return &upstairLight;
    }else{
        upstairLight.next = phand;
        phand = &upstairLight;
        return phand;
    }
}
