/**
 * @file 5.5.find.minimum.in.rotated.sorted.array.ii
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
  int findMin(vector<int>& a) {
    int n = a.size(), l = 0, r = n - 1;

    while (l < r) {
      int p = pvt(l, r);
      if (a[p] < a[r]) r = p;  // not p - 1: [3, 1, 3]
      else if (a[p] > a[r])
        l = p + 1;
      else
        --r;  // makes it linear on worst case
    }

    return a[l];
  }
};
