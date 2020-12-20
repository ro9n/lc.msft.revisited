/**
 * @file 1.11.set.matrix.zeros
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday December 15 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 2mn → O(mn) runtime O(mn) space using additional matrix, O(m + n) using mask for rows then cols, O(1) using first row and col as mask
  void setZeroes(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    bool row0 = 0, col0 = 0;

    for (int i = 0; i < n; ++i) if (!mat[i][0]) col0 = 1;
    for (int j = 0; j < m; ++j) if (!mat[0][j]) row0 = 1;

    for (int i = 1; i < n; ++i) for (int j = 1; j < m; ++j) 
        if (!mat[i][j]) mat[0][j] = mat[i][0] = 0;
    

    for (int i = 1; i < n; ++i) for (int j = 1; j < m; ++j)
        if (!mat[0][j] || !mat[i][0]) mat[i][j] = 0;
    

    if (col0) for (int i = 0; i < n; ++i) mat[i][0] = 0;
    if (row0) for (int j = 0; j < m; ++j) mat[0][j] = 0;
  }
};
