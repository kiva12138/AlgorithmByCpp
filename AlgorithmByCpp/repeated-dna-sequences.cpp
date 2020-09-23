#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string, int> saved;
        int len = 10;
        int maxSize = (int)s.size() - len + 1;
        for (int i = 0; i < maxSize; i++) {
            saved[s.substr(i, len)] ++;
        }
        for (unordered_map<string, int>::iterator it = saved.begin(); it != saved.end(); it ++) {
            if (it->second >= 2) {
                result.push_back(it->first);
            }
        }
        return result;
    }
};