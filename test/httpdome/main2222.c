#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include<stdlib.h>
#include <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>
#define true 1 ;
#define false 0 ;
typedef unsigned int bool;
char buf[1024] = {'\0'};
size_t readData(void *ptr,size_t size ,size_t nmemb,void *strem)
{
    
    strncpy(buf,ptr,1024); 
     
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
    int flielen;
    int flielen2;
   
    system("base64 1.jpeg > tmpFile");
    int fd1 = open("./tmpFile",O_RDWR); 
    flielen = lseek(fd1,0,SEEK_END); 
    lseek(fd1,0,SEEK_SET); 
    char *buf1 = (char *)malloc(flielen+2);
    memset(buf1,0,flielen+2); 
    read(fd1,buf1,flielen); 
    
    close(fd1);
    system("base64 2.jpeg > tmpFile2");
    int fd2 = open("./tmpFile2",O_RDWR); 
    flielen2 = lseek(fd2,0,SEEK_END); 
    lseek(fd2,0,SEEK_SET); 
    char *buf2 = (char *)malloc(flielen2+2);
    memset(buf2,0,flielen2+2); 
    read(fd1,buf2,flielen2);
    
    close(fd2);
    
    
    postString = (char *)malloc(strlen(key)+strlen(secret)+strlen(buf2)+strlen(buf1)+124);
   
    sprintf(postString,"&img1=%s&img2=%s&key=%s&secret=%s&typeId=%d&format=%s",buf1,buf2,key,secret,21,format);//合并


    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/tmp/cookie.txt"); // 指定cookie文件
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postString);    // 指定post内容
        curl_easy_setopt(curl, CURLOPT_URL, "https://netocr.com/api/faceliu.do");   // 指定url
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, readData); //将返回的html主体数据输出到fp指向的文件
        res = curl_easy_perform(curl);
        printf("OK :%d\n",res);
        if(strstr(buf,"是")!= NULL){
            printf("yes\n");
        }else{
            printf("no\n");
        }
        curl_easy_cleanup(curl);
    }
   
    return true;
}
int main(void)
{
    postUrl();
}