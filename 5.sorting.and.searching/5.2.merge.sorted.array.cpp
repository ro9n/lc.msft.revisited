/**
 * @file 5.2.merge.sorted.array
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
  void merge(vector<int>& a, int n, vector<int>& b, int m) {
    while (n > 0 && m > 0) {
      if (a[n - 1] < b[m - 1]) a[n + m - 1] = b[m - 1], --m;
      else
        a[n + m - 1] = a[n - 1], --n;
    }

    while (m > 0) {
      a[n + m - 1] = b[m - 1], --m;
    }
  }
};
