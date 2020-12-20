/**
 * @file 4.2.word.search.II
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday December 18 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ff    first
#define ss    second
#define WHITE 0
#define GREY  1

struct trie {
 public:
  trie* c[26];
  bool leaf;
};

void insert(trie* r, const string& s) {
  for (auto c : s) {
    if (!r->c[c - 97]) r->c[c - 97] = new trie();
    r = r->c[c - 97];
  }
  r->leaf = 1;
}

const pair<int, int> d[]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int color[12][12];
vector<string> ans;

void dfs(trie* t, int i, int j, const string& s, const vector<vector<char>>& board) {
  const int n = board.size(), m = board[0].size();

  if (t->leaf) ans.push_back(s), t->leaf = 0;  // or mark as visited [["a", "a"]]["a"]
  for (int dd = 0; dd < 4; ++dd) {
    int ii = i + d[dd].ff, jj = j + d[dd].ss;
    if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
    int c = board[ii][jj] - 97;
    if (t->c[c] && !color[ii][jj])
      color[ii][jj] = GREY, dfs(t->c[c], ii, jj, s + board[ii][jj], board), color[ii][jj] = WHITE;
  }
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (words.empty()) return {};
    auto t = new trie(); for (auto w : words) insert(t, w);

    const int n = board.size(), m = board[0].size();
    memset(color, WHITE, sizeof color);

    ans.clear();

    // linear to mat, m * n * nested call →
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int c = board[i][j] - 97;
        // → 3ᵏ, k = |longest matched word| ≣ 4⋅3ᴸ−¹
        if (t->c[c])
          color[i][j] = GREY, dfs(t->c[c], i, j, string(1, board[i][j]), board), color[i][j] = WHITE;  // [["a", "a"]]["aaa"]
      }
    }

    return ans;
  }
};