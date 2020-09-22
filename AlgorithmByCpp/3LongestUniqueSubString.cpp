#include <string>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // »¬¶¯´°¿Ú
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, maxlen = 0;
        for (r = 0; r < s.size(); r++) {
            for (int k = l; k < r; k++) {
                if (s[k] == s[r]) {
                    l = k + 1;
                    break;
                }
            }
            if (r - l + 1 > maxlen) {
                maxlen = r - l + 1;
            }
        }
        return maxlen;
    }

    void test() {
        cout << lengthOfLongestSubstring("abcabcbb");
    }
};