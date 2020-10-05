#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> nums1(nums.begin(), nums.begin() + nums.size()-1);
        vector<int> nums2(nums.begin()+1, nums.begin() + nums.size());
        return max(rob_sub(nums1), rob_sub(nums2));
    }

    int rob_sub(vector<int>& nums) {
        vector<int> result;
        result.resize(nums.size() + 1);
        result[0] = 0;
        result[1] = nums[0];
        for (long i = 1; i < nums.size(); i++) {
            result[i + 1L] = max(result[i], result[i - 1L] + nums[i]);
        }
        return result[nums.size()];
    }

    void test() {

    }
};