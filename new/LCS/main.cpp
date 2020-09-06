// Copyright [2020] <Copyright yourui>

#include <iostream>
#include <string>
#include <vector>

using namespace std;


string LCS(const string &a, const string &b) {
  int m = a.size(), n = b.size();
  string res = "";
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  vector<vector<int>> dir(m + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i-1] == b[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
        dir[i][j] = 1;  // 左上
      } else {
        if (dp[i-1][j] >= dp[i][j-1]) {
          dp[i][j] = dp[i-1][j];
          dir[i][j] = 2;  // 上
        } else {
          dp[i][j] = dp[i][j-1];
          dir[i][j] = 3;  // 左
        }
      }
    }
  }
  int i = m, j = n;
  while (i != 0 && j != 0) {
    if (dir[i][j] == 1) {
      res = a[i-1] + res;
      i--;
      j--;
    } else if (dir[i][j] == 2) {
      i--;
    } else if (dir[i][j] == 3) {
      j--;
    }
  }
  return res;
}

int main() {
  string a = "", b = "";
  while (cin >> a >> b) {
    cout << LCS(a, b) << endl;
  }
}