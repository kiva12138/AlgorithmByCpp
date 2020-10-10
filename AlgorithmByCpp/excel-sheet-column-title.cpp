#include "Utils.h"
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string convertToTitle(int n) {
        string word = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string result;
        int dst = 26;
        while (n != 0) {
            n--;
            int m = n % dst;
            n = n / dst;
            result = word.substr(m, 1) + result;
        }
        return result;
    }
    void test() {
        cout << convertToTitle(701);
    }
};