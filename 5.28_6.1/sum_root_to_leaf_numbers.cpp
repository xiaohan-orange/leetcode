#include<iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int help(TreeNode *root,int sum){
	if(root==NULL){
		return 0;
	}
	else if(root->left==NULL&&root->right==NULL){
		return sum*10+root->val;
	}
	else{
		return help(root->left,sum*10+root->val)+
			help(root->right,sum*10+root->val);
	}
}

int sumNumbers(TreeNode *root){
	if(root==NULL){
		return 0;
	}
	int ans=help(root,0);
	return ans;
}

int main(){
	TreeNode* tr1=new TreeNode(4);
	TreeNode* tr2=new TreeNode(9);
	TreeNode* tr3=new TreeNode(0);
	TreeNode* tr4=new TreeNode(5);
	TreeNode* tr5=new TreeNode(1);

	tr1->left=tr2;
	tr1->right=tr3;
	tr2->left=tr4;
	tr2->right=tr5;
	int ans=sumNumbers(tr1);
	cout<<ans<<endl;
	return 0;
}
