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
char* getPicBase64ForFile(char *filePath){
    char* bufpic = NULL; 
    char cmd[128]={'\0'}; 
    sprintf(cmd,"base64 %s > tmpFile",filePath); 

    system(cmd);
    int fd = open("./tmpFile",O_RDWR); 
    int flielen = lseek(fd,0,SEEK_END); 
    lseek(fd,0,SEEK_SET); 
    bufpic = (char *)malloc(flielen+2);
    memset(bufpic,0,flielen+2); 
    read(fd,bufpic,flielen); 
    close(fd);
    system("rm -rf tmpFile");
    return bufpic; 
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


    char *bufpic1 = getPicBase64ForFile("/home/pi/smartHost/picture/liuxu.jpg");
    char *bufpic2 = getPicBase64ForFile("/home/pi/smartHost/picture/imeag.jpg");
    
    postString = (char *)malloc(strlen(key)+strlen(secret)+strlen(bufpic1)+strlen(bufpic2)+124);
   
    sprintf(postString,"&img1=%s&img2=%s&key=%s&secret=%s&typeId=%d&format=%s",bufpic1,bufpic2,key,secret,21,format);//�ϲ�


    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/tmp/cookie.txt"); // ָ��cookie�ļ�
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postString);    // ָ��post����
        curl_easy_setopt(curl, CURLOPT_URL, "https://netocr.com/api/faceliu.do");   // ָ��url
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, readData); //�����ص�html�������������fpָ����ļ�
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