#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int N;
  cin >> N;
  vector<int> M(N);

  for (int i = 0; i < N; ++i) {
    cin >> M[i];
  }

  // 排序偏好
  sort(M.begin(), M.end());

  long long result = 1;
  for (int i = 0; i < N; ++i) {
    // 计算第 i 只兔子的选择数
    int choices = M[i] - i; // M[i] - (i + 1) + 1
    if (choices <= 0) {
      result = 0;
      break;
    }
    result = (result * choices) % MOD;
  }

  cout << result << endl;
  return 0;
}