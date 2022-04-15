#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <pthread.h>

typedef struct data {
	char name[30];
	unsigned int num;
}Data;

void print_err(char *str, int line, int err_no) {
	printf("%d, %s :%s\n",line,str,strerror(err_no));
	_exit(-1);
}
int cfd = -1;

//线程函数用于循环从cfd描述符中尝试接收数据
void *receive(void *pth_arg) {
	int ret = 0;
	Data stu_data = {0};
	while(1) {
		//初始化结构体变量
		bzero(&stu_data, sizeof(stu_data));
		ret = recv(cfd, &stu_data, sizeof(stu_data),0);	
		if (-1 == ret) {
			print_err("recv failed",__LINE__,errno);
		}
		//接收之后需要将网络端序转换为主机端序
		printf("student number = %d student name = %s \n",ntohl(stu_data.num),stu_data.name);
	}
}

int main()
{
	int skfd = -1, ret = -1;
	skfd = socket(AF_INET, SOCK_STREAM, 0);
	if ( -1 == skfd) {
		print_err("socket failed",__LINE__,errno);
	}

	struct sockaddr_in addr;
	addr.sin_family = AF_INET; //设置tcp协议族
	addr.sin_port = 6789; //设置端口号
	addr.sin_addr.s_addr = inet_addr("192.168.137.198"); //设置ip地址

	ret = bind(skfd, (struct sockaddr*)&addr, sizeof(addr));
	if ( -1 == ret) {
		print_err("bind failed",__LINE__,errno);
	}
	
 	/*将套接字文件描述符从主动转为被动文件描述符，然后用于被动监听客户端的连接*/
	ret = listen(skfd, 3);
	if ( -1 == ret ) {
		print_err("listen failed", __LINE__, errno);
	}

	/*被动监听客户端发起的tcp连接请求，三次握手后连接建立成功*/
	struct sockaddr_in caddr = {0};
	int csize = 0;
	cfd = accept(skfd, (struct sockaddr*)&caddr, &csize);
	if (-1 == cfd) {
		print_err("accept failed", __LINE__, errno);
	}
	printf("cport = %d, caddr = %s\n", ntohs(caddr.sin_port),inet_ntoa(caddr.sin_addr));
	
	//创建子线程用于接收数据
	pthread_t id;
	pthread_create(&id,NULL,receive,NULL);
	
	//发送数据结构体定义
	Data std_data = {0};
	while (1) {
		printf("stu name:\n");
		scanf("%s",std_data.name);
		
		
		printf("stu num:\n");
		scanf("%d",&std_data.num);
		//对于int型的需要将主机端序转换为网络端序，这里转成long型。
		std_data.num = htonl(std_data.num);
		
		//将数据std_data强制类型转换后发送
		ret = send(cfd, (void *)&std_data,sizeof(std_data),0);
		if ( -1 == ret) {
			print_err("accept failed", __LINE__, errno);
		}	
	}
	
	return 0;
}
