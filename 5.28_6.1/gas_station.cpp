#include<vector>
#include<iostream>
using namespace std;
int canCircuit(vector<int>& gas,vector<int>& cost){
	int total=0,sum=0,start=0;
	for(int i=0;i<gas.size();i++){
		total+=(gas[i]-cost[i]);
		if(sum<0){
			sum=gas[i]-cost[i];
			start=i;
		}
		else{
			sum+=(gas[i]-cost[i]);
		}
	}
	return total>=0?start:-1;
}
int main(){
	vector<int> gas={1,2,3,4,5};
	vector<int> cost={3,4,5,1,2};
	int ans=canCircuit(gas,cost);
	cout<<ans<<endl;
	return 0;
}
