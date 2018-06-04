#include<vector>
#include<iostream>
#include<limits.h>
using namespace std;
int minimumTotal(vector<vector<int>>& triangle){
	if(triangle.empty()||triangle[0].empty()){
		return 0;
	}
	vector<int> dp=triangle.back();
	int n = triangle.size();
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<=i;j++){
			dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
		}
	}
	return dp[0];
}
int main(){
	vector<vector<int>> sup{{2},{3,4},{6,5,7},{4,1,8,3}};
	int ans = minimumTotal(sup);
	cout<<ans<<endl;
	return 0;
}
