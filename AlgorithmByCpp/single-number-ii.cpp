#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

class Solution {
public:

    // ֻ��һ�����ֳ���һ�Σ���������
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for (auto x : nums) {
            once = (once ^ x) & (~twice);
            twice = (twice ^ x) & (~once);
        }
        return once;
    }

    void test() {

    }
};