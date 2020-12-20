/**
 * @file 3.4.binary.tree.zigzag.level.order.traversal
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday December 17 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef vector<int> vi;

#define ld left
#define rd right

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *r) {
    if (!r) return {};
    queue<TreeNode *> q; q.push(r);
    vector<vi> ans; vi tmp;

    int j = 0;
    while (!q.empty()) {
      int n = q.size();
      tmp.clear();
      for (int i = 0; i < n; ++i) {
        auto u = q.front();
        q.pop();
        tmp.push_back(u->val);
        if (u->ld) q.push(u->ld);
        if (u->rd) q.push(u->rd);
      }
      if (j & 1) reverse(tmp.begin(), tmp.end());
      ans.push_back(tmp), ++j;
    }

    return ans;
  }
};