/**
 * @file 2.4.add.two.numbers.II
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
  // O(n)
  ListNode *rev(ListNode *h) {
    ListNode *prv = 0, *nxt;

    while (h) {
      nxt = h->next, h->next = prv, prv = h, h = nxt;
    }

    return prv;
  }

  // O(max(|l1|, |l2|))
  ListNode *add(ListNode *l1, ListNode *l2) {
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

 public:
  // Linear :3
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    l1 = rev(l1), l2 = rev(l2);
    ListNode *l3 = add(l1, l2);
    return rev(l3);
  }
};