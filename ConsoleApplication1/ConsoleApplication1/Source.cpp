/*有一个整数val，如何在节点值有序的环形链表中插入一个节点值为val的节点，并且保证这个环形单链表依然有序。
给定链表的信息，及元素的值A及对应的nxt指向的元素编号同时给定val，请构造出这个环形链表，并插入该值。
测试样例：
[1, 3, 4, 5, 7], [1, 2, 3, 4, 0], 2
返回：{ 1, 2, 3, 4, 5, 7 }*/


#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class InsertValue {
public:
	ListNode* insert(vector<int> A, vector<int> nxt, int val) {
		// write code here
		int n = A.size();//查看原链表的长度
		ListNode *Node = new ListNode(val);
		if (n == 0){//原链表为空链表
			Node->next = Node;
			return Node;
		}
		else if (n == 1){//原链表为一个头结点或2个结点
			Node->next->val = A[0];
			Node->next->next = Node;
			return Node;
		}
		else {
			ListNode *head = new ListNode(A[0]);
			ListNode *temp = head;
			for (int i = 1; i < n; i++) { //构成环形链表
				temp->next = new ListNode(A[i]);
				temp = temp->next;
			}
			ListNode *p, *c;
			p = head; c = head->next;
			for (int i = 1; i<n; i++){
				if ((val >= p->val&&val <= c->val) || (val >= c->val&&val <= p->val)){//插入p与c之间
					break;
				}
				p = c; c = c->next;
			}
			p->next = Node;
			Node->next = c;
			return head;
		}
	}

};


class Divide {
public:
	ListNode* listDivide(ListNode* head, int val) {
		// write code here
		ListNode* node = new ListNode(val);
		if (head == NULL){
			return node;
		}
		else{
			ListNode* temp = head;
			int n = 1;
			while (temp->next != NULL){
				temp = temp->next;
				n++;
			}
			temp->next = node;//把val放在链尾
			ListNode* tail = node;
			ListNode* zerohead = new ListNode(0);
			zerohead->next = head;
			ListNode* pre = zerohead;
			ListNode* cur = zerohead->next;
			for (int i=0;i<n;i++){
				if (cur->val >val){
					pre->next = cur->next;
					temp = cur;
					cur = cur->next;
					temp->next = NULL;
					tail->next = temp;
					tail = tail->next;
				}
				else if (cur->val ==val){
					pre->next = cur->next;
					cur = cur->next;
				}
				else{
					pre = pre->next;
					cur = cur->next;
				}
				
			}			
			return head;
		}

	}
};

int main(){
	//InsertValue test;
	//vector<int> A = { 1, 3, 4, 5, 7 }; vector<int> nxt = { 1, 2, 3, 4, 0 }; int val = 2;
	//ListNode* ans = test.insert(A, nxt, val);

	Divide test;
	vector<int> A = { 1, 4, 2, 5 }; int val = 2;
	int n = A.size();
	ListNode *head = new ListNode(A[0]);
	ListNode *temp = head;
	for (int i = 1; i < n; i++) { //构成链表
		temp->next = new ListNode(A[i]);
		temp = temp->next;
	}
	ListNode *ans = test.listDivide(head, val);

	
	temp = ans;
	while (temp != NULL){
		cout << temp->val;
		temp = temp->next;
	}
	
	return 0;
}