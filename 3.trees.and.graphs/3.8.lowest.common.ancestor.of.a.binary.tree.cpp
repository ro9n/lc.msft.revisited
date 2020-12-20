/**
 * @file 3.8.lowest.common.ancestor.of.a.binary.tree
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

#define ld left
#define rd right

class Solution {
 public:
  // general case, will work for any form of btree
  // → 3.8
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    unordered_map<TreeNode *, TreeNode *> parent;
    int pd = -1, qd = -1;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *r, int d) {
      if (!r) return;
      else if (pd > 0 && qd > 0) return; // pruning subsequent calls
      else if (r == p)
        pd = d;
      else if (r == q)
        qd = d;

      if (r->ld) parent[r->ld] = r, dfs(r->ld, 1 + d);
      if (r->rd) parent[r->rd] = r, dfs(r->rd, 1 + d);
    };

    dfs(root, 0);

    while (pd < qd) q = parent[q], --qd;
    while (pd > qd) p = parent[p], --pd;

    while (p != q) {
      p = parent[p], q = parent[q];
    }

    return p;
  }
};