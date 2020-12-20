/**
 * @file 1.8.longest.palindromic.substring
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
  // O(n²)
  string longestPalindrome(string s) {
    int n = s.size(), dp[n][n];
    pair<int, int> best = {0, 1};

    for (int l = 1; l < n; ++l) {
      for (int i = 0; i < n - l; ++i) { int j = i + l;
        dp[i][j] = s[i] == s[j] && (i + 1 >= j - 1 ? 1 : dp[i + 1][j - 1]);
        if (dp[i][j] && j - i + 1 > best.second) best = {i, j - i + 1};
      }
    }

    return s.substr(best.first, best.second);
  }
};