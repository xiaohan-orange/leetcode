class CSingleton{
private:
	CSingleton(){}
	//声明拷贝构造函数和拷贝赋值运算符
	//为了解决Singleton singleton = Singleton::GetInstance()
	//编译器会生成一个默认的构造函数，来支持类的拷贝
	//返回指针，则没有这种问题
	CSingleton(const CSingleton &);
	CSingleton& operator=(const CSingleton &);
public:
	static CSingleton & GetInstance(){
		static CSingleton instance;//局部静态变量
		return instance;
	}
};
