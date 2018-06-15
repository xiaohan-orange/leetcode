#include<sys/types.h>//UNIX、linux系统的基本系统数据类型
#include<sys/socket.h>//套接字接口
#include<netinet/in.h>//INTERNET地址族
#include<arpa/inet.h>//INTERNET定义
#include<unistd.h>//提供对POSIX系统API的访问
#include<stdio.h>
#include<stdlib.h>//定义杂项函数及内存分布函数
#include<strings.h>//从UNIX系统继承而来，定义了一些字符串函数
#include<sys/wait.h>//进程控制
#include<string.h>
#include<errno.h>

int MyRecv(int iSock,char* pchBuf,size_t tCount){
	size_t tBytesRead=0;
	int iThisRead;
	while(tBytesRead<tCount){
		do{
			iThisRead=read(iSock,pchBuf,tCount-tBytesRead);
		}while((iThisRead<0)&&(errno==EINTR));
		if(iThisRead<0){
			return(iThisRead);
		}
		else if(iThisRead==0){
			return(tBytesRead);
		}
		tBytesRead+=iThisRead;
		pchBuf+=iThisRead;
	}
}

#define DEFAULT_PORT 6666

int main(int argc,char** argv){
	int sockfd,acceptfd;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	unsigned int sin_size,myport=6666,lisnum=10;
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1){
		perror("socket");
		return -1;
	}
	printf("socket ok!\n");
	memset(&my_addr,0,sizeof(my_addr));
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(DEFAULT_PORT);
	my_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))==-1){
		perror("bind");
		return -2;
	}
	printf("bind ok!\n");
	if(listen(sockfd,lisnum)==-1){
		perror("listen");
		return -3;
	}
	printf("listen ok!\n");
	char recvMsg[10];
	sin_size=sizeof(my_addr);
	acceptfd=accept(sockfd,(struct sockaddr*)&my_addr,&sin_size);
	if(acceptfd<0){
		close(sockfd);
		printf("accept failed!\n");
		return -4;
	}
	ssize_t readLen=MyRecv(acceptfd,recvMsg,sizeof(int));
	if(readLen<0){
		printf("read failed!\n");
		return -1;
	}
	int len=(int)ntohl(*(int *)recvMsg);
	printf("len:%d\n",len);
	readLen=MyRecv(acceptfd,recvMsg,len);
	if(readLen<0){
		printf("read failed!\n");
		return -1;
	}
	recvMsg[len]='\0';
	printf("recvMsg:%s\n",recvMsg);
	close(acceptfd);
	return 0;
}

