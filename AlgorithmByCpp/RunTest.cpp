#include "repeated-dna-sequences.cpp"
#include "Utils.h"
#include <iostream>
using namespace std;

int main() {
	Solution s;
	vector<string> result = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	printVector(result);
	cout << "Hello world";
	return 0;
}