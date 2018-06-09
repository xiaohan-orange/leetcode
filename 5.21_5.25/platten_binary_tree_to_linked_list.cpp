#include<iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
void flatten(TreeNode* root){
	if(!root){
		return;
	}
	if(root->left){
		flatten(root->left);
	}
	if(root->right){
		flatten(root->right);
	}
	if(root->left==NULL){
		return;
	}
	TreeNode* tmp = root->right;
	root->right = root->left;
	while(root->right){
		root=root->right;
	}
	root->right=tmp;
}
int main(){
	TreeNode* tmp1 = new TreeNode(1);
	TreeNode* tmp2 = new TreeNode(2);
	TreeNode* tmp3 = new TreeNode(3);
	TreeNode* tmp4 = new TreeNode(4);
	TreeNode* tmp5 = new TreeNode(5);
	TreeNode* tmp6 = new TreeNode(6);
	tmp1->left = tmp2;
	tmp1->right = tmp5;
	tmp2->left = tmp3;
	tmp2->right = tmp4;
	tmp5->right = tmp6;
	flatten(tmp1);
	TreeNode* cur = tmp1;
	while(cur){
		cout<<cur->val<<endl;
		cur=cur->right;
	}
	return 0;
}
