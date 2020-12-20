/**
 * @file 6.1.best.time.to.buy.and.sell.stock
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
  // brute force, tle, O(n²)
  int maxProfit(vector<int>& prices) {
    int n = prices.size(), ans = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ans = max(ans, prices[j] - prices[i]);
      }
    }

    return ans;
  }

  // 1 pass
  int maxProfit(vector<int>& prices) {
    const int INF = 1e9 + 7;
    int n = prices.size(), best = 0, mn = INF;

    for (auto p : prices) {
      mn = min(mn, p), best = max(best, p - mn);
    }

    return best;
  }
};
