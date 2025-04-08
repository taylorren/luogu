#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  for (int i = 0; i < s.length(); i++) {
    // 计算移动后的位置，使用取模运算处理循环
    int new_pos = ((s[i] - 'a' + n) % 26);
    s[i] = 'a' + new_pos;
  }

  cout << s << endl;
  return 0;
}