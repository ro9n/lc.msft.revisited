/**
 * @file 5.8.search.a.2d.matrix.ii
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday December 19 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // n + m
  bool searchMatrix(vector<vector<int>>& mat, int k) {
    if (mat.empty()) return 0;
    int n = mat.size(), m = mat[0].size();

    for (int i = n - 1, j = 0; i >= 0 && j < m;) {  // pick bottom left or top right, so there is only one answer whether to go left or right
      int& x = mat[i][j];
      if (x == k) return 1;
      else if (x < k)
        ++j;
      else
        --i;
    }

    return 0;
  }
};