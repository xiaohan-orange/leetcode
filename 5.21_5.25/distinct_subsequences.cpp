#include<iostream>
#include<vector>
#include<string>
using namespace std;
int numDistinct(string s,string t){
	vector<vector<int>> ans(t.length()+1,vector<int>(s.length()+1,0));
	for(int i = 0;i<s.length()+1;i++){
		ans[0][i]=1;
	}
	for(int i = 1;i<t.length()+1;i++){
		ans[i][0]=0;
	}
	for(int i = 1;i<t.length()+1;i++){
		for(int j = 1;j<s.length()+1;j++){
			ans[i][j]=ans[i][j-1]+
				(t[i-1]==s[j-1]?ans[i-1][j-1]:0);
		}
	}
	return ans[t.length()][s.length()];
}
int main(){
	string s = "babgbag";
	string t = "bag";
	int a = numDistinct(s,t);
	cout<<a<<endl;
	return 0;
}
