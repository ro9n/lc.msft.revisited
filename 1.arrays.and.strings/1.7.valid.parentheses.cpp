/**
 * @file 1.7.valid.parentheses
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday December 14 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;
unordered_map<int, int> m{
    {')', '('},
    {'}', '{'},
    {']', '['}};

class Solution {
 public:
  // O(n)
  bool isValid(string s) {
    stack<int> S;

    for (auto c : s) {
      if (m.count(c)) {
        if (S.empty() || S.top() != m[c]) return 0;
        S.pop();
      } else S.push(c);
    }

    return S.empty();
  }
};