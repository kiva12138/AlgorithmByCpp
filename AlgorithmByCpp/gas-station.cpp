#include <iostream>
#include "Utils.h"

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int roadLen = gas.size();
        for (int i = 0; i < roadLen; i++) {
            // Start Form Station i
            if (gas[i] < cost[i]) {
                continue;
            }
            bool successReach = true;
            int current = i;
            int next = current + 1;
            int remain_gas = gas[current];
            while (successReach) {
                if (next == roadLen) {
                    next = 0;
                }
                remain_gas = remain_gas - cost[current];
                if (remain_gas < 0) {
                    successReach = false;
                }
                else {
                    if (next == i) {
                        return i;
                    }
                    current = next;
                    next += 1;
                    remain_gas += gas[current];
                }
            }
        }
        return -1;
    }

    void test() {
        vector<int> gas  = { 4 };
        vector<int> cost = { 5 };
        cout << canCompleteCircuit(gas, cost);
    }
 };
