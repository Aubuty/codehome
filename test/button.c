#include <stdio.h>
#include "wiringPi.h"
#include<stdlib.h>
#define BUTTON  7
 
int main()
{
    char ficecmd[127]={'\0'};
    wiringPiSetup();
    pinMode(BUFSIZ, INPUT);
    pullUpDnControl(BUTTON, PUD_UP);
    while(1)
    {
        if(digitalRead(BUTTON) == LOW)
        {
            delay(20); // 延时销抖
            if(digitalRead(BUTTON) == LOW)
            {
                //sprintf(ficecmd,"wget  http://192.168.137.67:8080/?action=snapshot -O /home/pi/smartHost/picture/imeag.jpg");
                printf("adas\n");
                system(ficecmd);
                
            }
        }
        delay(100);
    }
}
