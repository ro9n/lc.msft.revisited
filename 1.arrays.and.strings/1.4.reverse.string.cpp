/**
 * @file 1.4.reverse.string
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
  void reverseString(vector<char>& s) {
    int n = s.size();

    for(int l = 0, r = n - 1; l < r; ++l, --r) {
      swap(s[l], s[r]);
    }
  }
};
