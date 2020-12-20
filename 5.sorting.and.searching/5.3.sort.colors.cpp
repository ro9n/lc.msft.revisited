/**
 * @file 5.3.sort.colors
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
  // 1 pass
  void sortColors(vector<int>& a) {
    int n = a.size();

    for (int i = 0, l = 0, r = n - 1; i <= r;) {
      cout << a[i] << endl;
      if (!a[i]) {
        if (l != i) swap(a[i], a[l]);
        ++l, ++i;
      } else if (a[i] == 2) {
        if (i != r) swap(a[i], a[r]);
        --r;
      } else
        ++i;
    }
  }
  // const space 2 pass
  void sortColors(vector<int>& nums) {
    int f[3];
    memset(f, 0, sizeof f);
    for (auto k : nums) ++f[k];
    for (int i = 0, j = 0; i < 3; ++i) {
      while (f[i] > 0) nums[j++] = i, --f[i];
    }
  }
};