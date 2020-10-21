#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

class Solution {
public:

    // ֻ��һ�����ֳ���һ�Σ�����2��
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            result = result ^ *it;
        }
        return result;
    }

    void test() {
        vector<int> nums = { 2,2,3 };
        cout << singleNumber(nums);
    }
};