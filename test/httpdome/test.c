#include <stdio.h>
#include <curl/curl.h>
#define true 1 ;
#define false 0 ;
typedef unsigned int bool;
char buf[1024] = {'\0'};
size_t readData(void *ptr,size_t size ,size_t nmemb,void *strem)
{
    
    strncpy(buf,ptr,1024); 
     
}

int postUrl(char *filename)
{
    CURL *curl;
    CURLcode res;
    FILE *fp;
    curl = curl_easy_init();
    if (curl)
    {
        
        
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/tmp/cookie.txt"); // ָ��cookie�ļ�
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "&logintype=uid&u=xieyan&psw=xxx86");    // ָ��post����
        //curl_easy_setopt(curl, CURLOPT_PROXY, "10.99.60.201:8080");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
        curl_easy_setopt(curl, CURLOPT_URL, " http://mail.sina.com.cn/cgi-bin/login.cgi ");   // ָ��url
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    fclose(fp);
    return 1;
}
int main(void)
{
    postUrl("/tmp/post.html");
}