#include<vector>
#include<stack>

using namespace std;

int evelRPN(vector<string>& tokens){
	if(tokens.size()==1){
		return stoi(tokens[0]);
	}
	stack<int> sta;
	for(int i=0;i<tokens.size();i++){
		if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/"){
			sta.push(stoi(tokens[i]));
		}
		else{
			int a=sta.top();
			sta.pop();
			int b=sta.top();
			sta.pop();
			if(tokens[i]=="+"){
				sta.push(b+a);
			}
			if(tokens[i]=="-"){
				sta.push(b-a);
			}
			if(tokens[i]=="*"){
				sta.push(b*a);
			}
			if(tokens[i]=="/"){
				sta.push(b/a);
			}
		}
	}
	return sta.top();
}
