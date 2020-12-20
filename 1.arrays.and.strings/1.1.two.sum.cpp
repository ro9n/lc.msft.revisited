/**
 * @file 1.1.two.sum
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday December 14 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // O(n)
  vector<int> twoSum(vector<int>& v, int k) {
    unordered_map<int, int> m;
    int n = v.size();

    for (int i = 0; i < n; ++i) {
      if (m.count(k - v[i])) return {m[k - v[i]], i};
      else
        m[v[i]] = i;
    }

    return {};
  }
};
