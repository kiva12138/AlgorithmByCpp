#include <iostream>
#include <unordered_map>
#include "Utils.h"
#include "Node.cpp"

using namespace std;


class Solution {
public:
    unordered_map<Node*, Node*> myMap;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        if (myMap.find(node) == myMap.end()) {
            Node* newNode = new Node(node->val);
            myMap[node] = newNode;
            for (vector<Node*>::iterator iter = node->neighbors.begin(); iter != node->neighbors.end(); iter++) {
                newNode->neighbors.push_back(cloneGraph(*iter));
            }
            return newNode;
        }
        else {
            return myMap[node];
        }
    }
    void test() {

    }
};