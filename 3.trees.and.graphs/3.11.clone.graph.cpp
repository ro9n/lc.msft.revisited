/**
 * @file 3.11.clone.graph
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
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

#define WHITE 0
#define GREY  1
// #define BLACK 2

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    map<Node*, Node*> m;
    int color[101]; memset(color, WHITE, sizeof color);

    function<void(Node*)> dfs = [&](Node* u) {
      if (!u || color[u->val]) return;

      color[u->val] = GREY, m[u] = new Node(u->val);

      for (auto v : u->neighbors) {
        dfs(v), m[u]->neighbors.push_back(m[v]);
      }

      // color[u->val] = BLACK;
    };

    dfs(node);
    return m[node];
  }
};