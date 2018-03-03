#include "SLLStructure.cpp"

using namespace std;

class Solution {
public:
	void insertAtTail(ListNode **tail, ListNode *t) {
		t->next = NULL;
		(*tail)->next = t;
		*tail = t;
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *newHead = (ListNode *)malloc(sizeof(ListNode)), *newTail(newHead), *temp(NULL);
		while (l1 && l2) {
			if (l1->val < l2->val) {
				temp = l1;
				l1 = l1->next;
			}
			else {
				temp = l2;
				l2 = l2->next;
			}
			insertAtTail(&newTail, temp);
		}
		if (l1)
			newTail->next = l1;
		if (l2)
			newTail->next = l2;
		return newHead->next;
	}
};