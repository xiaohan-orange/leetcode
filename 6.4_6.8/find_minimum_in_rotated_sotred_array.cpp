#include<vector>
#include<iostream>

using namespace std;

int findMin(vector<int>& nums){
	int left=0,right=nums.size()-1;
	if(nums[left]>nums[right]){
		while(left!=(right-1)){
			int mid=(left+right)/2;
			if(nums[mid]<nums[left]){
				right=mid;
			}
			else{
				left=mid;
			}
		}
		return min(nums[left],nums[right]);
	}
	return nums[0];
}

int main(){
	vector<int> res={4,5,6,7,0,1,2};
	int ans=findMin(res);
	cout<<ans<<endl;
	return 0;
}
