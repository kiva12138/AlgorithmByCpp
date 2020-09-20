#include "2SumOfList.cpp"
#include "Utils.h"
#include <iostream>
using namespace std;

int main() {
	vector<int> v2 = { 5};
	vector<int> v1 = { 5};
	Solution s;
	printList(s.addTwoNumbers(constructFromVector(v1), constructFromVector(v2)));
	return 0;
}