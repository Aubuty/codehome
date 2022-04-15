#include<wiringPi.h>
#include<stdio.h>
#define led1 21
#define led2 22
#define led3 23
#define led4 24
int main()
{
    wiringPiSetup();
    pinMode(led1,OUTPUT); 
    pinMode(led2,OUTPUT); 
    pinMode(led3,OUTPUT); 
    pinMode(led4,OUTPUT); 
    digitalWrite(led1,HIGH); 
    digitalWrite(led2,HIGH); 
    digitalWrite(led3,HIGH); 
    digitalWrite(led4,HIGH); 
    int data; 
    while (1)
    {
        scanf("%d",&data); 
        switch (data)
        {
        case 11:
            digitalWrite(led1,LOW);
            break;
        case 21:
            digitalWrite(led2,LOW);
            break;
        case 31:
            digitalWrite(led3,LOW);
            break;
        case 41:
            digitalWrite(led4,LOW);
            break;
        case 10:
            digitalWrite(led1,HIGH);
            break;
        case 20:
            digitalWrite(led2,HIGH);
            break;
        case 30:
            digitalWrite(led3,HIGH);
            break;
        case 40:
            digitalWrite(led4,HIGH);
            break;
        case 0:
            digitalWrite(led1,HIGH);
            digitalWrite(led2,HIGH);
            digitalWrite(led3,HIGH);
            digitalWrite(led4,HIGH);
            break;
        case 1:
            digitalWrite(led4,LOW);
            digitalWrite(led1,LOW);
            digitalWrite(led2,LOW);
            digitalWrite(led3,LOW);
            break;
        }
        // digitalWrite(led1,!(digitalRead(led1)));
        // digitalWrite(led2,!(digitalRead(led2)));
        // digitalWrite(led3,!(digitalRead(led3)));
        // digitalWrite(led4,!(digitalRead(led4)));
        delay(50);
        /* code */
    }
    
}