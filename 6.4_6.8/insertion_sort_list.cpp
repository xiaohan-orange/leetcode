#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* insertionSortList(ListNode* head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	ListNode* beforehead=new ListNode(-1);
	beforehead->next=head;
	ListNode* cur,*com,*beforecur;
	cur=head->next;
	com=beforehead;
	beforecur=head;
	while(cur){
		if(cur->val>beforecur->val){
			beforecur=cur;
			cur=cur->next;
			continue;
		}
		else{
			while(com->next->val<cur->val){
				com=com->next;
			}
			beforecur->next=cur->next;
			cur->next=com->next;
			com->next=cur;
			cur=beforecur->next;
			com=beforehead;
		}
	}
	return beforehead->next;
}
