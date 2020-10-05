#include <iostream>
#include <vector>
#include <unordered_set>
#include "Utils.h"

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> found;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if (found.count(*it) >= 1) {
                return true;
            }
            else {
                found.insert(*it);
            }
        }
        return false;
    }

    void test() {
        vector<int> nums = { 1,1,1,3,3,4,3,2,4,2 };
        cout << containsDuplicate(nums);
    }
};