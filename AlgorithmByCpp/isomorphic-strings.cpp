#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        map<char, char> knownMap;
        map<char, char>::iterator iter;
        set<char> knownValue;
        int nSize = (int)s.size();
        for (int i = 0; i < nSize; i++) {
            iter = knownMap.find(s[i]);
            if (iter == knownMap.end()) {
                if (knownValue.find(t[i]) != knownValue.end()) {
                    return false;
                }
                knownMap.insert(pair<char, char>(s[i], t[i]));
                knownValue.insert(t[i]);
            }
            else if(knownMap.find(s[i])->second != t[i]) {
                return false;
            }
        }
        return true;
    }

    void test() {
        cout << isIsomorphic("ab", "aa") << "\n";
    }
};