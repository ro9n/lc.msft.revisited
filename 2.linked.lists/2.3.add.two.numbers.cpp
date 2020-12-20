/**
 * @file 2.3.add.two.numbers
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday December 16 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  // O(max(|l1|, |l2|))
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int c = 0;
    ListNode *dummy = new ListNode(0), *r = dummy;

    while (l1 || l2 || c) {
      int op1 = l1 ? l1->val : 0,
          op2 = l2 ? l2->val : 0,
          sum = op1 + op2 + c;

      c = sum / 10, sum %= 10;
      r->next = new ListNode(sum);
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
      r = r->next;
    }

    return dummy->next;
  }
};
