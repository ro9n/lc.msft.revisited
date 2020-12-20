/**
 * @file 1.10.trapping.rain.water
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
  // O(n²) - Quadratic using DP, O(n) - linear using 2 pointers
  int trap(vector<int>& h) {
    int n = h.size(), l = 0, r = n - 1, ans = 0, L = 0, R = 0;
    while (l < r) {
      L = max(L, h[l]), R = max(R, h[r]);
      if (h[l] < h[r]) ans += min(L, R) - h[l++];
      else
        ans += min(L, R) - h[r--];
    }

    return ans;
  }
};
