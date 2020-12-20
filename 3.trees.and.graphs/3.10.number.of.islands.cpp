/**
 * @file 3.10.number.of.islands
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday December 17 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define LAND  '1'
#define WATER '0'
#define ff    first
#define ss    second

class Solution {
 public:
  int numIslands(vector<vector<char>> &g) {
    int c = 0, n = g.size(), m = g[0].size();

    const vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    function<void(int, int)> ff = [&](int i, int j) {
      for (int dd = 0; dd < 4; ++dd) {
        int ii = i + d[dd].ff, jj = j + d[dd].ss;
        if (ii < 0 || ii >= n || jj < 0 || jj >= m || g[ii][jj] == WATER) continue;
        g[ii][jj] = WATER, ff(ii, jj);
      }
    };

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (g[i][j] == LAND) g[i][j] = WATER, ++c, ff(i, j);
      }
    }

    return c;
  }
};