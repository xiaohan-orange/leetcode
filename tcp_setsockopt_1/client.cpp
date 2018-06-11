#include<stdio.h>//标准IO文件
#include<stdlib.h>//定义杂项函数及内存分配函数
#include<string.h>//字符串函数
#include<errno.h>//定义错误码
#include<sys/types.h>//UNIX/linux系统的基本数据类型
#include<sys/socket.h>//套接字接口
#include<netinet/in.h>//INTERNET地址族(数据结构sockaddr_in)
#include<arpa/inet.h>//INTERNET定义(IP地址转换函数)
#include<unistd.h>//提供通用的文件，目录，程序及进程操作的函数

#define MAXLINE 4096

int main(int argc,char** argv){
    int connfd,n;
    char recvline[4096],sendline[4096];
    struct sockaddr_in servaddr;
    if(argc!=2){
        printf("usage: ./client 不是两个参数\n");
        return 0;
    }
    if((connfd=socket(AF_INET,SOCK_STREAM,0))<0)//当第三个参数为0时，会自动匹配
        //type类型对应的默认协议
    {
        printf("create socket error:%s(errno:%d)\n",strerror(errno),errno);
        return 0;
    }
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(6666);
    //地址转换函数，点分十进制->二进制整数
    if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<=0){
        printf("inet_pton error for %s\n",argv[1]);
        return 0;
    }
    if(connect(connfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0){
        printf("connfd error:%s(errno:%d)\n",strerror(errno),errno);
        return 0;
    }
    //用于设置socket的发送和接收超时时间
    struct timeval stTimeValStruct;
    stTimeValStruct.tv_sec=2;
    stTimeValStruct.tv_usec=0;
    if(setsockopt(connfd,SOL_SOCKET,SO_SNDTIMEO,&stTimeValStruct,
                sizeof(stTimeValStruct))){
        printf("setsocketopt error:%s(errno:%d)\n",strerror(errno),errno);
        return 0;
    }
    if(setsockopt(connfd,SOL_SOCKET,SO_RCVTIMEO,&stTimeValStruct,
                sizeof(stTimeValStruct))){
        printf("setsocketopt error:%s(errno:%d)\n",strerror(errno),errno);
        return 0;
    }
    ssize_t writeLen;
    char sendMsg[10]={'0','1','2','3','4','5','6','7','8','\0'};
    int count=0;
    writeLen=write(connfd,sendMsg,sizeof(sendMsg));
    if(writeLen<0){
        printf("write error:%s(errno:%d)\n",strerror(errno),errno);
        close(connfd);
        return 0;
    }
    else{
        printf("write success,writeLen:%d,sendMsg:%s\n",writeLen,sendMsg);
    }
    char readMsg[10]={0};
    int readlen=read(connfd,readMsg,sizeof(readMsg));
    if(readlen<0){
        printf("read error:%s(errno:%d)\n",strerror(errno),errno);
        close(connfd);
        return 0;
    }
    else{
        readMsg[9]='\0';
        printf("read success,readlen:%d,readMsg:%s\n",readlen,readMsg);
    }
    close(connfd);
    return 0;
}
