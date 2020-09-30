#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            //  result += n % 2;
            result += n & 1;
            n >> 1;
        }
        return result;
    }

    void test() {

    }
};