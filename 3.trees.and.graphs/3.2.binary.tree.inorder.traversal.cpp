/**
 * @file 3.2.binary.tree.inorder.traversal
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
  // iterative
  vector<int> inorderTraversal(TreeNode *r) {
    vector<int> ans; stack<TreeNode*> s;

    while (!s.empty() || r) {
      while (r) s.push(r), r = r->left;
      r = s.top(), s.pop(), ans.push_back(r->val), r = r->right;
    }

    return ans;
  }

  // recursive
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;

    function<void(TreeNode *)> dfs = [&](TreeNode *r) {
      if (!r) return;
      dfs(r->left), ans.push_back(r->val), dfs(r->right);
    };

    dfs(root);
    return ans;
  }
};