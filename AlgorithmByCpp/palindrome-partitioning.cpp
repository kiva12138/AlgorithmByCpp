#include <iostream>
#include <vector>
#include <string>
#include "Utils.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> subResult;

    bool isPalindrome(string str) {
        int len = str.size();
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            if (str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }

    void subPartition(string& str, int start) {
        int len = str.size();
        if (start >= len) {
            result.push_back(subResult);
            return;
        }
        for (int i = start; i < len; i++) {
            if (isPalindrome(str.substr(start, i - start + 1))) {
                subResult.push_back(str.substr(start, i - start + 1));
            }
            else {
                continue;
            }
            subPartition(str, i + 1);
            subResult.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        result.clear();
        subResult.clear();
        subPartition(s, 0);
        return result;
    }

    void test() {
        string s = "aab";
        vector<vector<string>> result = partition(s);
        for (int i = 0; i < result.size(); i++) {
            printVector(result.at(i));
        }
    }
};