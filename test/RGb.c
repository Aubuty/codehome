#include<wiringPi.h>
#include<stdio.h>
#include<stdlib.h>
#define led1 21
#define led2 22
#define led3 23
#define led4 24
int main()
{
    wiringPiSetup();
    char data[4] = {led1,led2,led3,led4};
    pinMode(led1,OUTPUT); 
    pinMode(led2,OUTPUT); 
    pinMode(led3,OUTPUT); 
    pinMode(led4,OUTPUT); 
    digitalWrite(led1,HIGH); 
    digitalWrite(led2,HIGH); 
    digitalWrite(led3,HIGH); 
    digitalWrite(led4,HIGH); 
    int magic;
    int num1 = 0, num2 = 4;
    while (1)
    {
        magic = rand() % num2 + num1;
        digitalWrite(data[magic],HIGH);
        digitalWrite(data[magic],HIGH);
        
        delay(30);
        digitalWrite(data[magic],LOW);
        digitalWrite(data[magic],LOW);
        
        delay(30);

    }
    
   
    
    
}