#include <iostream>
using namespace std;

// 计算组合数 nCk
int combination(int m, int n) {
  int result = 1;
  for (int i = n; i > n - m; i--) {
    result *= i;
  }
  for (int i = m; i > 1; i--) {
    result /= i;
  }
  return result;
}

int main() {
  string s;
  cin >> s;

  int n = s.size();
  int ans = 0;

  // Step 1: 检查输入单词是否按升序排列
  for (int i = 1; i < n; i++) {
    if (s[i] <= s[i - 1]) {
      cout << 0 << endl;
      return 0;
    }
  }

  // Step 2: 计算长度小于字母数的单词数量
  for (int i = 1; i < n; i++) {
    ans += combination(i, 26);
  }

  // Step 3: 处理单词中每个字符的位置
  for (int i = 0; i < n; i++) {
    for (char ch = (i == 0 ? 'a' : s[i - 1] + 1); ch < s[i]; ch++) {
      ans += combination(n - i - 1, 'z' - ch);
    }
  }

  // 加上1得最终结果
  cout << ++ans << endl;

  return 0;
}
