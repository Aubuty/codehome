#include"contrlDevices.h"
#define led1 21
#define led2 22
#define led3 23
#define led4 24
#define look 1
void pininit(){
    pinMode(led1,OUTPUT); 
    pinMode(led2,OUTPUT); 
    pinMode(led3,OUTPUT); 
    pinMode(led4,OUTPUT); 
    pinMode(look,OUTPUT); 
    digitalWrite(led1,HIGH); 
    digitalWrite(led2,HIGH); 
    digitalWrite(led3,HIGH); 
    digitalWrite(led4,HIGH);
    digitalWrite(look,HIGH);
}
void closeALL(){
    digitalWrite(led1,HIGH); 
    digitalWrite(led2,HIGH); 
    digitalWrite(led3,HIGH); 
    digitalWrite(led4,HIGH);
}
void OpenALL(){
    digitalWrite(led1,LOW); 
    digitalWrite(led2,LOW); 
    digitalWrite(led3,LOW); 
    digitalWrite(led4,LOW);
}

