#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include "Utils.h"

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.size() == 0) {
            return 0;
        }
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        unordered_map<string, unordered_set<string>> relations;
        unordered_set<string> used;
        list<pair<string, int>> findingList;

        for (unordered_set<string>::iterator it = wordSet.begin(); it != wordSet.end(); it++) {
            string tempString = *it;
            for (long i = 0; i < tempString.size(); i++) {
                string general1 = tempString.substr(0, i - 0);
                int end = i + 1;
                string general2 = tempString.substr(end, tempString.size() - i);
                string general = general1.append("*").append(general2);
                if (relations.find(general) == relations.end()) {
                    unordered_set<string> relation;
                    relation.insert(tempString);
                    relations.insert(make_pair(general, relation));
                }
                else {
                    relations.find(general)->second.insert(tempString);
                }
            }
        }

        int currentStep = 1;
        findingList.push_back(make_pair(beginWord, currentStep));
        used.insert(beginWord);
        string currentString;
        while (!findingList.empty()) {
            currentString = findingList.front().first;
            findingList.pop_front();
            currentStep++;
            for (long i = 0; i < currentString.size(); i++) {
                string general1 = currentString.substr(0, i - 0);
                int end = i + 1;
                string general2 = currentString.substr(end, currentString.size() - i);
                string general = general1.append("*").append(general2);
                
                unordered_map<string, unordered_set<string>>::iterator target = relations.find(general);
                if (target == relations.end()) {
                    continue;
                }
                for (unordered_set<string>::iterator it = target->second.begin(); it != target->second.end(); it++) {
                    if (used.find(*it) != used.end()) {
                        continue;
                    }
                    else {
                        if (endWord.compare(*it) == 0) {
                            return currentStep;
                        }
                        used.insert(*it);
                        findingList.push_back(make_pair(*it, currentStep));
                    }
                }
            }
        }

        return 0;
    }

    void test() {
        string beginWord = "hit";
        string endWord = "cog";
        vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
        cout << ladderLength(beginWord, endWord, wordList);
    }
};