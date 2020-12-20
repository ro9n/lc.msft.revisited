/**
 * @file 2.7.intersection.of.two.linked.lists
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
  ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) return 0;
    
    ListNode *h1 = l1, *h2 = l2;
    bool h1s = 0, h2s = 0;

    while (1) {
      if (h1 == h2) return h1;
      else if (!h1 && !h1s)
        h1 = l2, h1s = 1;
      else if (!h2 && !h2s)
        h2 = l1, h2s = 1;
      else if (!h1 || !h2)
        return 0;
      else
        h1 = h1->next, h2 = h2->next;
    }
  }

  ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
    unordered_set<ListNode *> s;
    while (l1) {
      s.insert(l1), l1 = l1->next;
    }

    while (l2) {
      if (s.count(l2)) return l2;
      else
        l2 = l2->next;
    }
    return 0;
  }
};
