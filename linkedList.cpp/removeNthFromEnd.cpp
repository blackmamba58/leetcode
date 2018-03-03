#include "SLLStructure.cpp"

using namespace std;

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *temp = head, *preHead, *iter;
		while (--n)
			temp = temp->next;

		iter = preHead = (ListNode *) malloc(sizeof(ListNode));
		preHead->next = head;
		
		while (temp->next) {
			temp = temp->next;
			iter = iter->next;
		}
		iter->next = iter->next->next;

		return preHead->next;
	}
};