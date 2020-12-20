/**
 * @file 1.2.valid.palindrome
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
  bool isPalindrome(string s) {
    int n = s.size(), l = 0, r = n - 1;

    while (l < r) {
      while (l < r && !isalnum(s[l])) ++l;
      while (l < r && !isalnum(s[r])) --r;
      if (tolower(s[l++]) != tolower(s[r--])) return 0;
    }
    return 1;
  }
};