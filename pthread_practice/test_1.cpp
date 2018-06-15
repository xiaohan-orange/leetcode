#include<stdio.h>
#include<pthread.h>
//如果线程调用的函数是在一个类中，应该把该函数写成静态成员函数！
//线程的运行函数，必须为void*，没说的表示返回通用指针，输入通用指针
void* say_hello(void* args){
	printf("hello from thread\n");
	//pthread_exit函数用于结束线程，唯一的参数是返回代码
	pthread_exit((void*)1);
}

int main(){
	pthread_t tid;//本质上是unsigned long int
	//线程创建，参数依次为，创建的线程id，线程参数，调用函数名，传入的函数参数
	//返回值为0时表示创建成功，否则返回错误编号
	int iRet=pthread_create(&tid,NULL,say_hello,NULL);
	if(iRet){
		printf("pthread_create error:iRet=%d\n",iRet);
		return iRet;
	}
	void* retval;
	//用来等待一个线程的结束，参数分别为：被等待的线程标识符，用来存储被等待的
	//线程返回值的指针
	iRet=pthread_join(tid,&retval);
	if(iRet){
		printf("pthread_join error:iRet=%d\n",iRet);
		return iRet;
	}
	printf("retval=%ld\n",(long)retval);
	return 0;
}
