#include<vector>
#include<iostream>
using namespace std;
int singleNumber(vector<int>& nums){
	int res=0;
	for(int i=0;i<32;i++){
		int sum=0;
		for(int j=0;j<nums.size();j++){
			sum+=(nums[j]>>i)&1;
		}
		res|=(sum%3)<<i;
	}
	return res;
}

int main(){
	vector<int> num={0,1,0,1,0,1,99};
	int ans=singleNumber(num);
	cout<<ans<<endl;
	return 0;
}
