#include "SLLStructure.cpp"

class Solution {
public:
	void insertAtBegining(ListNode **head, ListNode **tail, ListNode *t) {
		t->next = *head;
		if (*head == NULL)
			*tail = t;
		*head = t;
	}
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return true;
		int count = 0;
		ListNode *slow(head), *fast(head), *newHead(NULL), *newTail(NULL), *temp;
		while (fast) {
			fast = fast->next;
			count++;
			while (fast) {
				fast = fast->next;
				temp = slow->next;
				insertAtBegining(&newHead, &newTail, slow);
				slow = temp;
				count++;
			}
		}
		if (count & 1) {
			slow = slow->next;
		}
		while (newHead) {
			if (newHead->val != slow->val)
				return false;
			newHead = newHead->next;
			slow = slow->next;
		}
		return true;
	}
};
