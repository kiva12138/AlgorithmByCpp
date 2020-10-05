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

 // TreeNode
 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
