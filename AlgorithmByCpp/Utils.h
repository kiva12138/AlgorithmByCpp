#pragma once
#include <vector>

using namespace std;

template<class T>

// Print the vector by cout
void printVector(vector<T>&);

// Test for printVector Function
void testPrintVector();

// ListNode
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
 void printList(ListNode*);

 ListNode* constructFromVector(vector<int>& nums);