/**
 * @file 6.2.maximum.subarray
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
  int maxSubArray(vector<int>& a) {
    if (a.empty()) return 0;

    int best = a[0];

    for (int i = 1, n = a.size(); i < n; ++i) {
      if (a[i - 1] > 0) a[i] += a[i - 1];
      best = max(best, a[i]);
    }

    return best;
  }

  int maxSubArray(vector<int>& a) {
    if (a.empty()) return 0;

    int sum = a[0], best = a[0];

    for (int i = 1, n = a.size(); i < n; ++i) {
      sum = max(a[i], sum + a[i]);
      best = max(best, sum);
    }

    return best;
  }
};
