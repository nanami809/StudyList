��һ������val������ڽڵ�ֵ����Ļ��������в���һ���ڵ�ֵΪval�Ľڵ㣬���ұ�֤������ε�������Ȼ����
�����������Ϣ����Ԫ�ص�ֵA����Ӧ��nxtָ���Ԫ�ر��ͬʱ����val���빹���������������������ֵ��
����������
[1, 3, 4, 5, 7], [1, 2, 3, 4, 0], 2
���أ�{ 1, 2, 3, 4, 5, 7 }

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
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