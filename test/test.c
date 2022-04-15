#include <stdio.h>
#include<wiringPi.h>
 
#define LED0 1 // 设置GPIO0为控制LED的引脚
 
int main()
{
printf("Hello world\n");
 
wiringPiSetup(); // 初始化gpio
pinMode(LED0, OUTPUT); // 设置gpio0为输出模式
 
while (1) {
// 设置GPIO0为高电平
printf("Set GPIO0 : H\n");
digitalWrite(LED0, HIGH);
delay(50);
 
// 设置GPIO0为低电平
printf("Set GPIO0 : L\n");
digitalWrite(LED0, LOW);
delay(50);
}
 
return 0;
}