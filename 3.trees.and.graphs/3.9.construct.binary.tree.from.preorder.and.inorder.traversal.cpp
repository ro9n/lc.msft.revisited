/**
 * @file 3.9.construct.binary.tree.from.preorder.and.inorder.traversal
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

class Solution {
 public:
  TreeNode *buildTree(vector<int> &pre, vector<int> &in) {
    int n = pre.size();
    map<int, int> m;  // inorder indices

    for (int i = 0; i < n; ++i) m[in[i]] = i;
    reverse(pre.begin(), pre.end());  // for effecient popping from back after selecting each root

    function<TreeNode *(int, int)> build_stree = [&](int L, int R) -> TreeNode * {
      if (L > R) return 0;
      int back = pre.back();
      pre.pop_back();
      TreeNode *r = new TreeNode(back);
      int k = m[back];
      r->left = build_stree(L, k - 1), r->right = build_stree(k + 1, R);
      return r;
    };

    return build_stree(0, n - 1);
  }
};