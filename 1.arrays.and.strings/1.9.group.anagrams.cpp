/**
 * @file 1.9.group.anagrams
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday December 15 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

// O(n lg n), using freqency for hashing will result in linear time
inline string h(string s) {
  sort(s.begin(), s.end());
  return s;
}

class Solution {
 public:
  // O(nk lg k), k = max(S[i])
  vector<vector<string>> groupAnagrams(vector<string>& S) {
    unordered_map<string, vector<string>> m;

    for (auto s : S) m[h(s)].emplace_back(s);
    vector<vector<string>> ans;
    for (auto e : m) ans.emplace_back(e.second);
    return ans;
  }
};
