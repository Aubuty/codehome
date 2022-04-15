#include <stdio.h>
#include<wiringPi.h>
#include<stdlib.h>

#define Pin 25
int main(){
    wiringPiSetup(); 
    int data ; 
    while (1)
    {
        data = digitalRead(Pin);
        printf("data = %d\n",data);
        
        /* code */
    }
    
}