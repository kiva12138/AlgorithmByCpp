#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {

    }

    void test() {
        string s = "aab";
        vector<vector<string>> result = partition(s);
        for (int i = 0; i < result.size(); i++) {
            printVector(result.at(i));
        }
    }
};