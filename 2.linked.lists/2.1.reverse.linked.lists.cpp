/**
 * @file 2.1.reverse.linked.lists
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
  ListNode *reverseList(ListNode *h) {
    ListNode *prv = 0, *nxt;

    while (h) {
      nxt = h->next, h->next = prv, prv = h, h = nxt;
    }

    return prv;
  }
};