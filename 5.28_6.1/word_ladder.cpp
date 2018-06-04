#include<queue>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
int ladderLength(string beginWord,string endWord,vector<string>& wordList){
	if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()){
		return 0;
	}
	unordered_set<string> sup(wordList.begin(),wordList.end());
	queue<pair<string,int>> que;
	que.push(make_pair(beginWord,1));
	sup.erase(beginWord);
	while(!que.empty()){
		auto val=que.front();
		que.pop();
		if(val.first==endWord){
			return val.second;
		}
		for(int i=0;i<val.first.size();i++){
			string str=val.first;
			for(int j=0;j<26;j++){
				str[i]='a'+j;
				if(sup.count(str)==1){
					que.push(make_pair(str,val.second+1));
					sup.erase(str);
				}
			}
		}
	}
	return 0;
}
int main(){
	vector<string> sup={"hot","dot","dog","lot","log","cog"};
	int ans=ladderLength("hit","cog",sup);
	cout<<ans<<endl;
	return 0;
}
