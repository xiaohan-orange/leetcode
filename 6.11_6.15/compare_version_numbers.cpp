#include<string>
#include<iostream>
#include<cctype>

using namespace std;

int compareVersion(string version1,string version2){
	int i=0,j=0;
	int n1=version1.length(),n2=version2.length();
	while(i<n1 ||  j<n2){
		string s1="";
		string s2="";
		while(i<n1&&version1[i]!='.'){
			s1+=version1[i++];
		}
		while(j<n2&&version2[j]!='.'){
			s2+=version2[j++];
		}
		int d1=atoi(s1.c_str());
		int d2=atoi(s2.c_str());
		if(d1>d2){
			return 1;
		}
		if(d1<d2){
			return -1;
		}
		i++;
		j++;
	}
	return 0;
}
