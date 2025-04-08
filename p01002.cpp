#include <iostream>
#include <vector>

using namespace std;

// Function to check if a point is controlled by the knight
bool isControlled(int x, int y, int kx, int ky) {
  if (x == kx && y == ky) {
    return true;
  }
  if ((abs(kx - x) + abs(ky - y) == 3) &&       // 曼哈顿距离为3
      (max((abs(kx - x)), abs(ky - y)) == 2)) { // 切比雪夫斯距离为2
    return true;
  }
  return false;
}

int main() {
  int n, m, kx, ky;
  cin >> n >> m >> kx >> ky;

  long long dp[21][21] = {};
  // Initialize the DP table
  // 第一行（最上面一行）都是1，因为只有一种走法
  for (int i = 0; i <= m; ++i) {
    if (isControlled(0, i, kx, ky)) {
      break;
    }

    dp[0][i] = 1;
  }
  // 第一列（最左边一列）都是1，因为只有一种走法
  for (int i = 0; i <= n; ++i) {
    if (isControlled(i, 0, kx, ky)) {
      break;
    }
    dp[i][0] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (isControlled(i, j, kx, ky)) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
  }

  cout << dp[n][m] << endl;

  return 0;
}