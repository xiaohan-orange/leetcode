#include<vector>
#include<iostream>
using namespace std;

int maxProduct(vector<int>& nums){
	if(nums.empty()){
		return 0;
	}
	int ans=nums[0];
	int mx=nums[0];
	int mn=nums[0];
	for(int i=1;i<nums.size();i++){
		if(nums[i]>0){
			mx=max(nums[i]*mx,nums[i]);
			mn=min(mn*nums[i],nums[i]);
		}
		else{
			int sup=mx;
			mx=max(mn*nums[i],nums[i]);
			mn=min(nums[i]*sup,nums[i]);
		}
		ans=max(mx,ans);
	}
	return ans;
}
