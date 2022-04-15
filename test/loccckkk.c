#include<wiringPi.h>
#define look 1
int main(){
    wiringPiSetup();
    pinMode(look,OUTPUT);
    while (1)
    {
        digitalWrite(look,!digitalRead(look));
        delay(20);
    }  
}