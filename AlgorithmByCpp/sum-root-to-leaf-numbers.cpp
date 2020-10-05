#include "Utils.h"
#include <iostream>

using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return sum + root->val;
        }
        sum += root->val;
        return dfs(root->left, 10 * sum) + dfs(root->right, 10 * sum);
    }

    void test() {

    }
};