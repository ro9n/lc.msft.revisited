/**
 * @file 5.4.find.minimum.in.rotated.sorted.array
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
      if (a[l] < a[r])  // no rotation in current window
        r = p - 1;      // always go left
      else {
        if (a[p] > a[r]) l = p + 1;  // lower value to the right
        else
          r = p;
      }
    }

    return a[l];
  }
};
