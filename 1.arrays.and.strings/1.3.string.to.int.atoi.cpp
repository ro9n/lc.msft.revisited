/**
 * @file 1.3.string.to.int.atoi
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday December 14 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

inline bool sign(char k) { return k == '+' || k == '-'; }

class Solution {
 public:
  // O(n)
  int myAtoi(string s) {
    int n = s.size(), l = 0;
    long k = 0;
    bool neg = 0;

    while (l < n && s[l] == ' ') ++l;
    if (sign(s[l])) {
      if (s[l] == '-') neg = 1;
      ++l;
    } else if (!isdigit(s[l]))
      return k;

    for (int r = l; r < n && isdigit(s[r]); ++r) {
      // range validation
      k *= 10, k += s[r] - '0';
      if (!neg && k > INT_MAX) return INT_MAX;
      else if (neg && -k < INT_MIN)
        return INT_MIN;
    }
    return neg ? -k : k;
  }
};
