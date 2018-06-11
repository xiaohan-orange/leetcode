#include<stdio.h>//标准输入输出文件
#include<stdlib.h>//定义杂项函数及内存分配函数
#include<string.h>//字符串处理
#include<errno.h>//定义错误码
#include<sys/types.h>//UNIX、linux系统的基本系统数据结构类型
#include<sys/socket.h>//定义套接字接口
#include<netinet/in.h>//INTERNET地址族
#include<unistd.h>//提供通用的文件，目录，程序及进程操作的函数

#define MAXLINE 4096

int main(int argc,char** argv){
    int listenfd,acceptfd;
    struct sockaddr_in servaddr;
    if((listenfd=socket(AF_INET,SOCK_STREAM,0))==-1){
        printf("create socket error:%s(errno:%d)\n",strerror(errno),errno);
        return 0;
    }
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(6666);
    if(bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr))==-1){
       printf("bind socket error:%s(errno:%d)\n",strerror(errno),errno);
       return -1;
    }
    if(listen(listenfd,10)==-1){
        printf("listen socket error:%s(errno:%d)\n",strerror(errno),errno);
        return -1;
    }
    printf("=====waiting for client's request=====\n");
    if((acceptfd=accept(listenfd,(struct sockaddr*)NULL,NULL))==-1){
        printf("accept error:%s(errno:%d)\n",strerror(errno),errno);
        return -1;
    }
    char recvMsg[100];
    ssize_t readLen=read(acceptfd,recvMsg,sizeof(recvMsg));
    if(readLen<0){
        printf("read error:%s(errno:%d)\n",strerror(errno),errno);
        return -1;
    }
    recvMsg[9]='\0';
    printf("readLen:%d,recvMsg:%s\n",readLen,recvMsg);
    sleep(5);
    recvMsg[1]='9';
    ssize_t writeLen=write(acceptfd,recvMsg,sizeof(recvMsg));
    printf("writenLen:%d,sendMsg:%s\n",writeLen,recvMsg);
    if(writeLen<0){
        printf("writenLen error:%s(errno:%d)\n",strerror(errno),errno);
        return -1;
    }
    close(acceptfd);
    return 0;
}
