/**
 * @file 2.2.linked.list.cycle
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday December 15 2020
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
  // O(n)
  bool hasCycle(ListNode *h) {
    if (!h) return 0;

    ListNode *s = h, *f = h->next;  // slow, fast pointers

    while (s) {
      if (s == f) return 1;
      else if (!f || !f->next)
        return 0;
      else {
        s = s->next, f = f->next->next;
      }
    }

    return 0;
  }
};
