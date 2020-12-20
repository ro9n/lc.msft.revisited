/**
 * @file 4.3.wildcard.matching
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday December 18 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isMatch(string t, string p) {
    int n = p.size(), m = t.size(), dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i)
      if (p[i] == '*') dp[i + 1][0] = dp[i][0];  // when * in pattern, value will follow last value without pattern, applies to col 0, row i

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int &ans = dp[i + 1][j + 1];
        if (p[i] == '*') ans = dp[i + 1][j] | dp[i][j + 1] | dp[i][j];  // without pattern, without text, without pattern and text
        else if (p[i] == '?')
          ans = dp[i][j];  // without pattern and text
        else
          ans = dp[i][j] & p[i] == t[j];  // default
      }
    }

    return dp[n][m];
  }
};
