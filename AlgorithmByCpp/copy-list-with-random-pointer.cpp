#include <iostream>
#include <vector>
#include <unordered_map>
#include "Utils.h"

using namespace std;


class Solution {
public:
    RandomNode* copyRandomList(RandomNode* head) {
        unordered_map<RandomNode*, RandomNode*> memo;
        if (!head) return nullptr;
        if (memo[head]) return memo[head];
        RandomNode* clone = new RandomNode(head->val);
        memo[head] = clone;
        clone->next = copyRandomList(head->next);
        clone->random = copyRandomList(head->random);
        return clone;
    }

    void test() {

    }
};