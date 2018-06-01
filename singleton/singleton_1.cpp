class CSingleton{
private:
	CSingleton(){}//构造函数是私有的
	static CSingleton *m_pInstance;
	//私有内嵌类，它的唯一工作是在析构函数中删除CSingleton的实例
	class CGarbo{
	public:
		~CGarbo(){
			if(CSingleton::m_pInstance){
				delete CSingleton::m_pInstance;
			}
		}
	};
	//定义一个静态变量，程序结束时，系统会自动调用它的析构函数
	static CGarbo Garbo;
public:
	static CSingleton* GetInstance(){
		if(m_pInstance==NULL){//判断是否为第一次使用
			m_pInstance=new CSingleton();
		}
		return m_pInstance;
	}
};
/*
   用户访问唯一实例的方法只有GetInstance()成员函数
   构造函数是私有的，如果不通过这个成员函数，任何创建实例的尝试都将失败
   GetInstance()使用懒惰初始化，它的返回值是当这个函数首次被访问是被创建的
   所有GetInstance()之后的调用都返回相同实例的指针
 */
