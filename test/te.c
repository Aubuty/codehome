#include <stdio.h>
#include <unistd.h>   //调用 sleep() 函数
#include <pthread.h>  //调用 pthread_create() 函数
#include<stdlib.h>
void *ThreadFun(void *arg)
{
    chdir("/home/pi/mjpg-streamer/mjpg-streamer-experimental");
    system("./mjpg_streamer -i \"./input_uvc.so\" -o \"./output_http.so -w ./www\" >/dev/null 2>&1");
}

int main()
{
    int res;
    pthread_t cameThread1;
    res = pthread_create(&cameThread1, NULL, ThreadFun, NULL);
    if (res != 0) {
        printf("线程创建失败");
        return 0;
    }
    pthread_join(cameThread1,NULL);
    return 0;
}