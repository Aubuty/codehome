//卫生间灯
#include"contrlDevices.h"
int bathroomLightopen(int pinNum)//on
{
    digitalWrite(pinNum,LOW);
    printf("11\n");
}   
int bathroomLightclose(int pinNum)//off
{
    digitalWrite(pinNum,HIGH);
    printf("10\n");
}
int bathroomLightInit(int pinNum)//init
{
    pinMode(pinNum,OUTPUT); 
    digitalWrite(pinNum,HIGH); 

}
int bathroomLightclosechange(int status)
{

}
struct Devices bathroomLight={
    .open = bathroomLightopen,
    .close = bathroomLightclose,
    .DevicesName = "bathroomLight",
    .DevicesInit = bathroomLightInit,
    .pinNum = 21,
    .changestatus = bathroomLightclosechange
};
struct Devices* addBathroomLightToDevicesLink(struct Devices* phand)
{
    printf("添加%s\n",bathroomLight.DevicesName);
    if(phand == NULL){
        return &bathroomLight;
    }else{
        bathroomLight.next = phand;
        phand = &bathroomLight;
        return phand;
    }
}
