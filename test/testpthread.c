#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include <unistd.h> 
void *mypthread(void *arg){
    while (1)
        {
            printf("woshi\n");
            sleep(2);
        }
}
void *mypthread2(void *arg){
    while (1)
        {
            printf("woshi123213\n");
            sleep(3);
        }
}
int main()
{
    // pthread_t t1;
    // pthread_t t2;
    // pthread_create(&t1,NULL,mypthread,NULL);
    // pthread_create(&t2,NULL,mypthread2,NULL);
    // while (1)
    // {
    //     printf("1\n");
    //     sleep(1);
    // }  

    
}