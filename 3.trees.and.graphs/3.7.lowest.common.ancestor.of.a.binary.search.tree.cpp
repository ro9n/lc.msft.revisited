/**
 * @file 3.7.lowest.common.ancestor.of.a.binary.search.tree
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
  // special case, will work for bstree only
  TreeNode *lowestCommonAncestor(TreeNode *r, TreeNode *p, TreeNode *q) {
    if (!r) return 0;

    while (1) {
      // keep going down till both p and q are on the same bucket
      if (p->val < r->val && q->val < r->val) r = r->ld;
      else if (p->val > r->val && q->val > r->val) r = r->rd;
      else return r;
    }
  }

  // general case, will work for any form of btree
  // → 3.8
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    map<TreeNode *, TreeNode *> parent;
    int pd = -1, qd = -1;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *r, int d) {
      if (!r) return;
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