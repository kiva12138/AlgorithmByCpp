#include "Utils.h"
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int index1 = 0;
        int index2 = (int)numbers.size() - 1;
        int temp = numbers.at(index1) + numbers.at(index2);
        while (temp != target) {
            if (temp < target) {
                index1++;
            }
            else {
                index2--;
            }
            temp = numbers.at(index1) + numbers.at(index2);
        }
        result.push_back(index1 + 1);
        result.push_back(index2 + 1);
        return result;
    }

    void test() {
        vector<int> numbers = { 2, 7, 11, 15 }; 
        vector<int> result = twoSum(numbers, 9);
        printVector(result);
    }
};