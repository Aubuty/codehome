#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define true 1 ;
#define false 0 ;
typedef unsigned int bool;
size_t readData(void *ptr,size_t size ,size_t nmemb,void *strem)
{
    char buf[1024] = {'\0'};
    strncpy(buf,ptr,1024); 
    printf("=================get Data=================\n"); 
    printf("%s\n",buf); 
}
bool postUrl()
{
    CURL *curl;
    CURLcode res;
    char *postString ; 
    char img1[123]; 
    char img2[123]; 
    char *key = "QiJwjne3hkv6ka4MV63p4v"; 
    char *secret = "dbc950e51ec14fc1ba0d940e27a720c9";
    int typeId = 21; 
    char *format = "xml";
    postString = (char *)malloc(strlen(key)+strlen(secret)+2048);
    sprintf(postString,"&img1=%s&img2=%s&key=%s&secret=%s&typeId=%d&format=%s","","",key,secret,21,format);
    int fd = open("./tmpFile",O_RDWR); 
    int flielen = lseek(fd,0,SEEK_END); 
    lessk(fd,0,SEEK_SET); 
    char *buf = (char *)malloc(flielen+2);
    memset(buf,0,flielen+2); 
    read(fd,buf,flielen); 
    printf("%s\n",buf);
    curl = curl_easy_init();
    
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/tmp/cookie.txt"); // 指定cookie文件
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postString);    // 指定post内容
        curl_easy_setopt(curl, CURLOPT_URL, "https://netocr.com/api/faceliu.do");   // 指定url
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, readData); //将返回的html主体数据输出到fp指向的文件
        res = curl_easy_perform(curl);
        printf("OK :%d\n",res);
        curl_easy_cleanup(curl);
    }
   
    return true;
}
int main(void)
{
    postUrl();
}