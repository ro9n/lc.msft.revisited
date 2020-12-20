/**
 * @file 5.6.search.in.rotated.sorted.array
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday December 19 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define pvt(l, r) l + (r - l >> 1)

class Solution {
 public:
  int search(vector<int>& a, int k) {
    int n = a.size(), l = 0, r = n - 1;
    while (l <= r) {
      int p = pvt(l, r);
      if (a[p] == k) return p;
      else if (a[l] <= a[p]) {  // sorted l...p
        if (a[l] <= k & k < a[p]) r = p - 1;
        else
          l = p + 1;
      } else {
        if (a[p] < k & k <= a[r])
          l = p + 1;
        else
          r = p - 1;
      }
    }

    return -1;
  }
};