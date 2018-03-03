#include "SLLStructure.cpp"

using namespace std;

class Solution {
public:
	void insertAtBegining(ListNode **head, ListNode *t) {
		if (*head == NULL) {
			t->next = NULL;
			*head = t;
			return;
		}
		t->next = *head;
		*head = t;
	}
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *newHead(NULL), *temp(NULL);
		while (head) {
			temp = head;
			head = head->next;
			insertAtBegining(&newHead, temp);
		}
		return newHead;
	}
};