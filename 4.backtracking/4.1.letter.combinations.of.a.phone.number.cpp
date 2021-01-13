/**
 * @file 4.1.letter.combinations.of.a.phone.number
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday December 18 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  const string t9[10]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxzy"};

 public:
  // 3ᴺ * 4ᴹ, N = number of digits which has 3 chars, M = 4 chars
  // worst 4 ^ N, N = |digits|
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> ans;
    int n = digits.size();

    function<void(int, string)> solve = [&](int i, string s) {
      if (i == n) ans.push_back(s);
      else {
        for (auto c : t9[digits[i] - '0']) solve(i + 1, s + c);
      }
    };

    solve(0, "");
    return ans;
  }
};

const string t9[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
    vector<string> letterCombinations(string d) {
      if (d.empty()) return {};
       vector<string> ans;
        int n = d.size();
        string curr = "";
        
        function<void(int)> solve = [&](int i) {
            if (i == n) ans.push_back(curr);
            else {
                for(auto c: t9[d[i] - 48]) {
                    curr += c, solve(i + 1), curr.pop_back();
                }
            }
        };
        
        solve(0);
        
        return ans;
    }
};