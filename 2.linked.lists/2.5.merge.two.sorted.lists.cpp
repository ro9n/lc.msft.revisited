/**
 * @file 2.5.merge.two.sorted.lists
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
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  // O(max(|l1|, |l2|)) time, space
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0), *r = dummy;

    while (l1 and l2) {
      if (l1->val < l2->val) r->next = new ListNode(l1->val), l1 = l1->next;
      else {
        r->next = new ListNode(l2->val), l2 = l2->next;
      }
      r = r->next;
    }

    if (l1) r->next = l1;
    else if (l2)
      r->next = l2;

    return dummy->next;
  }
};
