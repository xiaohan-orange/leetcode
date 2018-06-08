#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* merge(ListNode* l1,ListNode* l2){
	ListNode* dummy=new ListNode(-1);
	ListNode* cur=dummy;
	while(l1&&l2){
		if(l1->val<l2->val){
			cur->next=l1;
			l1=l1->next;
		}
		else{
			cur->next=l2;
			l2=l2->next;
		}
		cur=cur->next;
	}
	if(l1){
		cur->next=l1;
	}
	if(l2){
		cur->next=l2;
	}
	return dummy->next;
}

ListNode* sortList(ListNode* head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	ListNode *pre,*slow,*fast;
	slow=head;
	fast=head;
	while(fast && fast->next){
		pre=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	pre->next=NULL;
	return merge(sortList(head),sortList(slow));
}
