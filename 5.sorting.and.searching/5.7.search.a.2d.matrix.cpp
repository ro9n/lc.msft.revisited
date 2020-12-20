/**
 * @file 5.7.search.a.2d.matrix
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
  bool searchMatrix(vector<vector<int>>& mat, int k) {
    if (mat.empty()) return 0;
    int n = mat.size(), m = mat[0].size(), l = 0, r = n * m - 1;

    while (l <= r) {
      int p = l + (r - l >> 1);
      int rr = p / m, cc = p % m;

      if (mat[rr][cc] == k) return 1;
      else if (mat[rr][cc] < k)
        l = p + 1;
      else
        r = p - 1;
    }
    return 0;
  }
};