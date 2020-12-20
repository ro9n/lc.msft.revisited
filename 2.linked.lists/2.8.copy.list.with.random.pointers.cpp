/**
 * @file 2.8.copy.list.with.random.pointers
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday December 16 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return 0;

    Node *h;

    h = head; while (h) {
      Node *tmp = h->next;
      h->next = new Node(h->val);
      h->next->next = tmp;
      h = h->next->next;
    }

    h = head; while (h) {
      if (h->random) h->next->random = h->random->next;
      h = h->next->next;
    }

    h = head; Node *copy = head->next, *r = head->next;
    while (h) {
      h->next = h->next->next;
      if (copy->next) copy->next = copy->next->next;
      h = h->next, copy = copy->next;
    }

    return r;
  }

  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> m;

    Node* h = head;
    while (h) {
      m[h] = new Node(h->val);
      if (h->random) m[h->random] = new Node(h->random->val);
      h = h->next;
    }

    Node *dummy = new Node(0), *r = dummy;
    h = head;

    while (h) {
      r->next = m[h];
      if (h->random) r->next->random = m[h->random];
      h = h->next, r = r->next;
    }

    return dummy->next;
  }
};