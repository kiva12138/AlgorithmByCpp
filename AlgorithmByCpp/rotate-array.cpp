#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end() - k % nums.size());
        printVector(nums);
        reverse(nums.end() - k % nums.size(), nums.end());
        printVector(nums);
        reverse(nums.begin(), nums.end());
        printVector(nums);
    }

    void test() {
        vector<int> nums = { -1, -100, 3, 9 };
        rotate(nums, 2);
    }
};