/*��һ������val������ڽڵ�ֵ����Ļ��������в���һ���ڵ�ֵΪval�Ľڵ㣬���ұ�֤������ε�������Ȼ����
�����������Ϣ����Ԫ�ص�ֵA����Ӧ��nxtָ���Ԫ�ر��ͬʱ����val���빹���������������������ֵ��
����������
[1, 3, 4, 5, 7], [1, 2, 3, 4, 0], 2
���أ�{ 1, 2, 3, 4, 5, 7 }*/


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
		int n = A.size();//�鿴ԭ����ĳ���
		ListNode *Node = new ListNode(val);
		if (n == 0){//ԭ����Ϊ������
			Node->next = Node;
			return Node;
		}
		else if (n == 1){//ԭ����Ϊһ��ͷ����2�����
			Node->next->val = A[0];
			Node->next->next = Node;
			return Node;
		}
		else {
			ListNode *head = new ListNode(A[0]);
			ListNode *temp = head;
			for (int i = 1; i < n; i++) { //���ɻ�������
				temp->next = new ListNode(A[i]);
				temp = temp->next;
			}
			ListNode *p, *c;
			p = head; c = head->next;
			for (int i = 1; i<n; i++){
				if ((val >= p->val&&val <= c->val) || (val >= c->val&&val <= p->val)){//����p��c֮��
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
			temp->next = node;//��val������β
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
	for (int i = 1; i < n; i++) { //��������
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