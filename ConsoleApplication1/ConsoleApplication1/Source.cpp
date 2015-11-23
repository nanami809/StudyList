/*有一个整数val，如何在节点值有序的环形链表中插入一个节点值为val的节点，并且保证这个环形单链表依然有序。
给定链表的信息，及元素的值A及对应的nxt指向的元素编号同时给定val，请构造出这个环形链表，并插入该值。
测试样例：
[1, 3, 4, 5, 7], [1, 2, 3, 4, 0], 2
返回：{ 1, 2, 3, 4, 5, 7 }*/


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

/*对于一个链表，我们需要用一个特定阈值完成对它的分化，使得小于等于这个值的结点移到前面，大于该值的结点在后面，同时保证两类结点内部的位置关系不变。
给定一个链表的头结点head，同时给定阈值val，请返回一个链表，使小于等于它的结点在前，大于等于它的在后，保证结点值不重复。
测试样例：
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

/*现有两个升序链表，且链表中均无重复元素。请设计一个高效的算法，打印两个链表的公共值部分。
给定两个链表的头指针headA和headB，请返回一个vector，元素为两个链表的公共部分。请保证返回数组的升序。两个链表的元素个数均小于等于500。保证一定有公共值
测试样例：
{1,2,3,4,5,6,7},{2,4,6,8,10}
返回：[2.4.6]*/
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

/*有一个单链表，请设计一个算法，使得每K个节点之间逆序，如果最后不够K个节点一组，则不调整最后几个节点。例如链表1->2->3->4->5->6->7->8->null，K=3这个例子。调整后为，3->2->1->6->5->4->7->8->null。因为K==3，所以每三个节点之间逆序，但其中的7，8不调整，因为只有两个节点不够一组。
给定一个单链表的头指针head,同时给定K值，返回逆序后的链表的头指针。*/
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
		if (fast->next != NULL){//双数
			qHead = slow->next;
			slow->next = NULL;
			if (qHead->next == NULL){//2个结点
				if (pHead->val == qHead->val) return true;
				else return false;
			}

		}
		else{ //单数
			qHead = slow;
			if (qHead->next->next == NULL){//3个结点
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
	for (int i = 1; i < n; i++) { //构成链表
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