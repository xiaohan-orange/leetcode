#include<string>
#include<iostream>
using namespace std;

void reverseWords(string &s){
	if(s.empty()){
		return;
	}
	int n=s.size();
	int index=0;
	reverse(s.begin(),s.end());
	for(int i=0;i<n;i++){
		if(s[i]!=' '){
			if(index!=0){
				s[index++]=' ';
			}
			int j=i;
			while(j<n&&s[j]!=' '){
				s[index++]=s[j++];
			}
			reverse(s.begin()+index-(j-i),s.begin()+index);
			i=j;
		}
	}
	s.resize(index);
}
