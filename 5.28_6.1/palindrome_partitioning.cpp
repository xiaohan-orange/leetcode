#include<string>
#include<vector>
#include<iostream>
using namespace std;
bool ispalindrome(string s){
	int l=0;
	int r=s.length()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			return false;
		}
		l++;
		r--;
	}
	return true;
}
void help(string s,vector<vector<string>>& res,vector<string>& sup){
	for(int i=1;i<s.length();i++){
		if(ispalindrome(s.substr(0,i))){
			sup.push_back(s.substr(0,i));
			help(s.substr(i),res,sup);
			sup.pop_back();
		}
	}
	if(ispalindrome(s)){
		sup.push_back(s);
		res.push_back(sup);
		sup.pop_back();
	}
}
vector<vector<string>> partition(string s){
	vector<vector<string>> res;
	vector<string> sup;
	if(s.empty()){
		return res;
	}
	help(s,res,sup);
	return res;
}

int main(){
	vector<vector<string>> res;
	res=partition("aab");
	for(auto& a:res){
		for(auto& b:a){
			cout<<b<<endl;
		}
	}
	return 0;
}
