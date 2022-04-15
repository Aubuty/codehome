//餐厅灯
#include"contrlDevices.h"
int restaurantLightopen(int pinNum)//on
{
    digitalWrite(pinNum,LOW);
}   
int restaurantLightclose(int pinNum)//off
{
    digitalWrite(pinNum,HIGH);

}
int restaurantLightInit(int pinNum)//init
{
    pinMode(pinNum,OUTPUT); 
    digitalWrite(pinNum,HIGH); 

}
int restaurantLightclosechange(int status)
{

}
struct Devices restaurantLight={
    .open = restaurantLightopen,
    .close = restaurantLightclose,
    .DevicesName = "restaurantLight",
    .DevicesInit = restaurantLightInit,
    .pinNum = 24,
    .changestatus = restaurantLightclosechange

};
struct Devices* addrestaurantLightToDevicesLink(struct Devices* phand)
{
    printf("添加%s\n",restaurantLight.DevicesName);
    if(phand == NULL){
        return &restaurantLight;
    }else{
        restaurantLight.next = phand;
        phand = &restaurantLight;
        return phand;
    }
}