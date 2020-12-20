/**
 * @file 4.4.regular.expression.matching
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday December 18 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

inline bool eq(const char &p, const char &t) {
  return p == '.' | p == t;
}

class Solution {
 public:
  bool isMatch(string t, string p) {
    int n = p.size(), m = t.size(), dp[n + 1][m + 1];

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    // covers case "x*" as prefix
    for (int i = 0; i < n; ++i)
      if (p[i] == '*') dp[i + 1][0] = dp[i - 1][0];  // before (char leading *) → -2

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int &ans = dp[i + 1][j + 1];
        if (p[i] == '*') {
          // 0
          ans = dp[i - 1][j + 1];
          // 1
          ans |= dp[i][j + 1] & eq(p[i - 1], t[j]);
          // 1+
          ans |= dp[i + 1][j] & eq(p[i - 1], t[j]);  // refers to the new text for ongoing pattern
        } else
          ans = dp[i][j] && eq(p[i], t[j]);
      }
    }

    return dp[n][m];
  }
};
