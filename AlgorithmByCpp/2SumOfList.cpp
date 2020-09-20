#include "Utils.h"
#include "math.h"
#include <iostream>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode vHead(0), * p = &vHead;
        bool flag = false;
        while (l1 != NULL && l2 != NULL) {
            int temp = l1->val + l2->val;
            if (flag) {
                temp += 1;
                flag = false;
            }
            if (temp >= 10) {
                flag = true;
                temp = temp - 10;
            }
            p->next = new ListNode(temp);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == NULL && l2 == NULL) {
            if (flag) {
                p->next = new ListNode(1);
            }
            return vHead.next;
        }
        if (l2 == NULL) {
            l2 = l1;
        }
        while (l2 != NULL) {
            int temp = l2->val;
            if (flag) {
                temp += 1;
                flag = false;
            }
            if (temp >= 10) {
                flag = true;
                temp = temp - 10;
            }
            p->next = new ListNode(temp);
            p = p->next;
            l2 = l2->next;
        }
        if (flag) {
            p->next = new ListNode(1);
        }
        return vHead.next;
    }
};