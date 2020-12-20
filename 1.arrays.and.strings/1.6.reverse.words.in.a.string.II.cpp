/**
 * @file 1.6.reverse.words.in.a.string.II
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday December 14 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

inline void reverse(vector<char>& s, int l, int r) {
  while (l < r) swap(s[l++], s[r--]);
}

class Solution {
 public:
  // O(n)
  void reverseWords(vector<char>& s) {
    int n = s.size();

    reverse(s, 0, n - 1);

    int l = 0, r;
    while (l < n) {
      r = l;
      while (r < n && s[r] != ' ') ++r;
      reverse(s, l, r - 1), l = r + 1;
    }
  }
};
