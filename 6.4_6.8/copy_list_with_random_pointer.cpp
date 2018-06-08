#include<iostream>
#include<unordered_map>
using namespace std;
struct RandomListNode{
	int label;
	RandomListNode *next,*random;
	RandomListNode(int x):label(x),next(NULL),random(NULL){}
};

RandomListNode* copyRandomList(RandomListNode *head){
	if(head==NULL){
		return NULL;
	}
	RandomListNode* res=new RandomListNode(head->label);
	RandomListNode* node=res;
	RandomListNode* cur=head->next;
	unordered_map<RandomListNode*,RandomListNode*> m;
	m[head]=res;
	while(cur){
		RandomListNode* tmp=new RandomListNode(cur->label);
		node->next=tmp;
		m[cur]=tmp;
		node=node->next;
		cur=cur->next;
	}
	node=res;
	cur=head;
	while(node){
		node->random=m[cur->random];
		node=node->next;
		cur=cur->next;
	}
	return res;
}
