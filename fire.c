// //火灾
#include"contrlDevices.h"
int fileInit(int pinNum)//init
{
    pinMode(pinNum,INPUT); 
    digitalWrite(pinNum,HIGH); 

}

int firestatrerade(int pinNum){
    return digitalRead(pinNum);
}
struct Devices firestatus={
    
    .DevicesName = "fileifOrnot",
    .DevicesInit = fileInit,
    .readstatus = firestatrerade,
    .pinNum = 25

};
struct Devices* addfirestatusToDevicesLink(struct Devices* phand)
{
    printf("添加%s\n",firestatus.DevicesName);
    if(phand == NULL){
        return &firestatus;
    }else{
        firestatus.next = phand;
        phand = &firestatus;
        return phand;
    }
}