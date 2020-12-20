/**
 * @file 5.1.remove.duplicates.from.sorted.array
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
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size(), j = 1;

    for (int i = 1; i < n; ++i) {
      if (nums[i - 1] != nums[i]) {
        if (i != j) nums[j++] = nums[i];
        else
          ++j;
      }
    }

    return j;
  }
};
