/**
 * @file 6.3.longest.increasing.subsequence
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday December 20 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& a) {
    int n = a.size(), best = 1, dp[n], nxt[n];
    memset(dp, 0, sizeof dp);

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        int& ans = dp[i];
        if (i == j) ans = 1;
        else {
          if (a[i] < a[j]) ans = max(ans, dp[j] + 1);
          best = max(best, dp[i]);
        }
      }
    }

    return best;
  }
};
