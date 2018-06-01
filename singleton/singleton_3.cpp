class CSingleton{
private:
	CSingleton(){}
	static CSingleton *Instance;
public:
	static CSingleton* GetInstance(){
		if(Instance==NULL){
			Lock();
			if(Instance==NULL){
				Instance=new CSingleton;
			}
			UnLock();
		}
		return Instance;
	}
};
