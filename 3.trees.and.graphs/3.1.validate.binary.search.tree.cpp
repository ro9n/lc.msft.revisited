/**
 * @file 3.1.validate.binary.search.tree
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

bool valid(TreeNode *r, TreeNode *mn, TreeNode *mx) {
  if (!r) return 1;
  else if ((mn && r->val <= mn->val) || (mx && r->val >= mx->val))
    return 0;
  else
    return valid(r->left, mn, r) && valid(r->right, r, mx);
}

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    return valid(root, 0, 0);
  }
};