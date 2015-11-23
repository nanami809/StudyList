/*��һ������val������ڽڵ�ֵ����Ļ��������в���һ���ڵ�ֵΪval�Ľڵ㣬���ұ�֤������ε�������Ȼ����
�����������Ϣ����Ԫ�ص�ֵA����Ӧ��nxtָ���Ԫ�ر��ͬʱ����val���빹���������������������ֵ��
����������
[1, 3, 4, 5, 7], [1, 2, 3, 4, 0], 2
���أ�{ 1, 2, 3, 4, 5, 7 }*/


#include<stdio.h>
#include<vector>
#include<iostream>
#include<stack>
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

/*����һ������������Ҫ��һ���ض���ֵ��ɶ����ķֻ���ʹ��С�ڵ������ֵ�Ľ���Ƶ�ǰ�棬���ڸ�ֵ�Ľ���ں��棬ͬʱ��֤�������ڲ���λ�ù�ϵ���䡣
����һ�������ͷ���head��ͬʱ������ֵval���뷵��һ������ʹС�ڵ������Ľ����ǰ�����ڵ��������ں󣬱�֤���ֵ���ظ���
����������
{1,4,2,5},3
{1,2,4,5}*/

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
			ListNode* tail = temp;
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
				else{
					pre = pre->next;
					cur = cur->next;
				}				
			}
		
				
			return zerohead->next;
		}

	}
};

/*�����������������������о����ظ�Ԫ�ء������һ����Ч���㷨����ӡ��������Ĺ���ֵ���֡�
�������������ͷָ��headA��headB���뷵��һ��vector��Ԫ��Ϊ��������Ĺ������֡��뱣֤����������������������Ԫ�ظ�����С�ڵ���500����֤һ���й���ֵ
����������
{1,2,3,4,5,6,7},{2,4,6,8,10}
���أ�[2.4.6]*/
class Common {
public:
	vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
		// write code here
		vector<int> ans;
		ListNode *p = headA;
		ListNode *q = headB;
		while (p != NULL&&q != NULL){
			if (p->val<q->val){
				p = p->next;
			}
			else if (p->val>q->val){
				q = q->next;
			}
			else{
				ans.push_back(p->val);
				p = p->next;
				q = q->next;
			}
		}
		return ans;

	}
};

/*��һ�������������һ���㷨��ʹ��ÿK���ڵ�֮�����������󲻹�K���ڵ�һ�飬�򲻵�����󼸸��ڵ㡣��������1->2->3->4->5->6->7->8->null��K=3������ӡ�������Ϊ��3->2->1->6->5->4->7->8->null����ΪK==3������ÿ�����ڵ�֮�����򣬵����е�7��8����������Ϊֻ�������ڵ㲻��һ�顣
����һ���������ͷָ��head,ͬʱ����Kֵ�����������������ͷָ�롣*/
class KInverse {
public:
	ListNode* inverse(ListNode* head, int k) {
		// write code here
		ListNode* zerohead = new ListNode(0);
		ListNode* pre = zerohead;
		ListNode* temp = head;
		while (temp != NULL){
			int i = 0;
			stack<int> s;
			ListNode* begin = temp;
			while (temp != NULL &&i<k){
				s.push(temp->val);
				temp = temp->next;
				i++;
			}
			ListNode* tail = temp;
			int n = s.size();
			if (n<k){
				pre->next = begin;
			}
			else{
				for (int j = 0; j<k; j++){
					ListNode* top = new ListNode(s.top());
					s.pop();
					pre->next = top;
					pre = pre->next;
				}
				pre->next = tail;
			}
		}
		return zerohead->next;
	}
};


class Palindrome {
public:
	bool isPalindrome(ListNode* pHead) {
		// write code here
		if (pHead == NULL || pHead->next == NULL) return pHead;
		ListNode *slow = pHead, *fast = pHead, *qHead;
		while (fast->next!=NULL&&fast->next->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast->next != NULL){//˫��
			qHead = slow->next;
			slow->next = NULL;
			if (qHead->next == NULL){//2�����
				if (pHead->val == qHead->val) return true;
				else return false;
			}

		}
		else{ //����
			qHead = slow;
			if (qHead->next->next == NULL){//3�����
				if (pHead->val == qHead->next->val) return true;
				else return false;
			}
		}
		ListNode *zeroHead = new ListNode(0);
		ListNode *temp1 = qHead, *temp2;
		while (temp1 != NULL){
			temp2 = zeroHead->next;
			zeroHead->next = temp1;
			qHead = qHead->next;
			temp1->next = temp2;
			temp1 = qHead;
		}
		qHead = zeroHead->next;
		ListNode *p = pHead, *q = qHead;
		while (p != NULL&&q != NULL){
			if (p->val != q->val) return false;
			p = p->next;
			q = q->next;
		}
		return true;

	}
};



int main(){
	//InsertValue test;
	//vector<int> A = { 1, 3, 4, 5, 7 }; vector<int> nxt = { 1, 2, 3, 4, 0 }; int val = 2;
	//ListNode* ans = test.insert(A, nxt, val);




	//vector<int> A = { 360,220,2 }; int val = 2;
	

	//Divide test;
	//ListNode *ans = test.listDivide(head, val);
	

	
	vector<int> A = { 1, 3, 4, 3, 1 ,1}; 

	int n = A.size();	
	ListNode *head = new ListNode(A[0]);
	ListNode *temp = head;
	for (int i = 1; i < n; i++) { //��������
		temp->next = new ListNode(A[i]);
		temp = temp->next;
	}

	Palindrome test;
	bool ans = test.isPalindrome(head);
	cout << ans;
	//KInverse test;
	//ListNode *ans = test.inverse(head, k);

	/*temp = ans;
	while (temp != NULL){
		cout << temp->val;
		temp = temp->next;
	}*/
	
	
	return 0;
}