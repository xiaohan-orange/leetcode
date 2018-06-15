#include<stdio.h>
#include<pthread.h>
#include<string.h>
//线程在调用函数时传入参数

struct arg_type{
	int a;
	char b[100];
};
void* say_hello(void* args){
	arg_type temp=*(arg_type*)args;
	printf("hello from thread,a=%d,b=%s\n",temp.a,temp.b);
	pthread_exit((void*)1);
}

int main(){
	pthread_t tid;
	arg_type temp;
	temp.a=10;
	char ch[100]="i am orange";
	strcpy(temp.b,ch);
	int iRet=pthread_create(&tid,NULL,say_hello,&temp);
	if(iRet){
		printf("pthread_create error:iRet=%d",iRet);
		return iRet;
	}
	void* retval;
	iRet=pthread_join(tid,&retval);
	if(iRet){
		printf("pthread_join error:iRet=%d",iRet);
		return iRet;
	}
	printf("retval=%ld\n",(long)retval);
	return 0;
}
