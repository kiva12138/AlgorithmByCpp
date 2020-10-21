#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
#include "Utils.h"

using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        int maxRating = 0, minRating = 99999;
        unordered_set<int> ratingSet;
        for (int i = 0; i < len; i++) {
            ratingSet.insert(ratings[i]);
            maxRating = max(maxRating, ratings[i]);
            minRating = min(minRating, ratings[i]);
        }
        vector<int> candy(len, 1);
        for (int i = minRating+1; i <= maxRating; i++) {
            if (ratingSet.find(i) == ratingSet.end()) {
                continue;
            }
            for (int j = 0; j < len; j++) {
                if (ratings[j] == i) {
                    int left_pos = j-1, right_pos=j+1, left_candy = candy[j], right_candy = candy[j];
                    if (j == 0) {
                        left_pos = j;
                    }
                    if (j == len - 1) {
                        right_pos = j;
                    }
                    if (ratings[j] > ratings[left_pos]) {
                        left_candy = candy[left_pos] + 1;
                    }
                    if (ratings[j] > ratings[right_pos]) {
                        right_candy = candy[right_pos] + 1;
                    }
                    candy[j] = max(left_candy, right_candy);
                }
            }
        }
        //printVector(candy);
        return accumulate(candy.begin(), candy.end(), 0);
    }

    int candyBest(vector<int>& ratings) {
        vector<int> v(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                v[i] = v[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                v[i] = max(v[i], v[i + 1] + 1);
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }

    void test() {
        vector<int> ratings = {1, 0, 2};
        printVector(ratings);
        cout << (int)candy(ratings);
    }
};