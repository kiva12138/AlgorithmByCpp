#include <iostream>
#include "Utils.h"

template<class T>

void printVector(vector<T>& target) {
	int nSize = (int)target.size();
	for (int i = 0; i < nSize; i++) {
		cout << target.at(i) << ", ";
	}
	cout << "\n";
}

void testPrintVector() {
	vector<int> a = { 1, 2, 3, 4, 5 };
	vector<float> b = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	vector<string> c = { "a", "b", "c", "d", "e" };
	printVector(a);
	printVector(b);
	printVector(c);
}

void printList(ListNode* target) {
	ListNode* temp = target;
	while (temp != NULL) {
		cout << (temp->val);
		temp = temp->next;
		cout << ", ";
	}
	cout << "\n";
}

ListNode* constructFromVector(vector<int>& nums)
{
	ListNode head(0);
	ListNode* pHead = &head;
	for (int i = 0; i < (int)nums.size(); i++) {
		pHead->next = new ListNode(nums[i]);
		pHead = pHead->next;
	}
	return head.next;
}
