#include <iostream>
using namespace std;

// 计算 Catalan 数的递归函数
long long catalan(int n) {
  if (n == 0 || n == 1)
    return 1; // 基础情况
  long long result = 0;
  for (int i = 1; i <= n; ++i) {
    result += catalan(i - 1) * catalan(n - i);
  }
  return result;
}

int main() {
  int n;
  cin >> n;                   // 输入 n
  cout << catalan(n) << endl; // 输出 Catalan 数
  return 0;
}