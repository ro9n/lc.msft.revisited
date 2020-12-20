/**
 * @file 3.6.populating.next.right.pointers.in.each.node.II
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday December 17 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

#define ld left
#define rd right

class Solution {
 public:
  Node* connect(Node* r) {
    if (!r) return 0;
    queue<Node*> q; q.push(r);

    while (!q.empty()) {
      int n = q.size(); Node *p = 0;
      for(int i = 0; i < n; ++i) {
        Node *u = q.front(); q.pop();
        if (p) p->next = u; p = u;
        if (u->ld) q.push(u->ld);
        if (u->rd) q.push(u->rd);
      }
    }

    return r;
  }
};