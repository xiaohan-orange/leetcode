#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool wordBreak(string s,vector<string>& wordDict){
	if(s.length()==0||wordDict.empty()){
		return false;
	}
	int len=s.length();
	vector<bool> dp(len+1,false);
	dp[0]=true;
	for(int i=0;i<len;i++){
		for(int j=i;j>=0;j--){
			if(dp[j]==true){
				string str=s.substr(j,i-j+1);
				if(find(wordDict.begin(),wordDict.end(),str)!=wordDict.end()){
					dp[i+1]=true;
					break;
				}
			}
		}
	}
	return dp[len];
}

int main(){
	vector<string> res={"leet","code"};
	bool ans=wordBreak("leetcode",res);
	cout<<ans<<endl;
	return 0;
}
