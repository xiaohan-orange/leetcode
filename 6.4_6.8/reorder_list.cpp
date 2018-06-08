#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

void reorderList(ListNode* head){
	if(head==NULL||head->next==NULL){
		return;
	}
	ListNode *preSlow=NULL;
	ListNode *slow=head,*fast=head;
	while(fast&&fast->next){
		preSlow=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	preSlow->next=NULL;
	ListNode* newBegin=slow;
	ListNode* last=newBegin->next;
	while(last){
		ListNode* temp=last->next;
		last->next=newBegin;
		newBegin=last;
		last=temp;
	}
	slow->next=NULL;
	fast=head;
	preSlow=NULL;
	while(fast){
		ListNode* temp=newBegin->next;
		newBegin->next=fast->next;
		fast->next=newBegin;
		fast=newBegin->next;
		preSlow=newBegin;
		newBegin=temp;
	}
	if(newBegin!=NULL){
		preSlow->next=newBegin;
	}
}
