#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
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
bool getUrl(char *filename)
{
    CURL *curl;
    CURLcode res;
    FILE *fp;
    if ((fp = fopen(filename, "w")) == NULL)  // ���ؽ�����ļ��洢
        return false;
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Accept: Agent-007");
    curl = curl_easy_init();    // ��ʼ��
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);// ��Э��ͷ
        curl_easy_setopt(curl, CURLOPT_URL,"http://www.baidu.com");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp); //�����ص�httpͷ�����fpָ����ļ�
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, readData); //�����ص�html�������������fpָ����ļ�
        res = curl_easy_perform(curl);   // ִ��
        if (res != 0) {

            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
        }
        fclose(fp);
        return true;
    }
}
bool postUrl(char *filename)
{
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/tmp/cookie.txt"); // ָ��cookie�ļ�
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "&logintype=uid&u=xieyan&psw=xxx86");    // ָ��post����
        curl_easy_setopt(curl, CURLOPT_URL, " http://mail.sina.com.cn/cgi-bin/login.cgi ");   // ָ��url
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
   
    return true;
}
int main(void)
{
    getUrl("/tmp/get.html");
    postUrl("/tmp/post.html");
}