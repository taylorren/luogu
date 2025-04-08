#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // 存储所有满足条件的三元组
  vector<tuple<int, int, int>> validTriplets;

  // 遍历A的取值范围
  for (int A = 100; A <= 333; A++) {
    int B = 2 * A;
    int C = 3 * A;

    // 已经保证A, B, C都是三位数，无需额外判断

    // 使用位掩码检查数字唯一性和不包含0
    int mask = 0;
    bool valid = true;
    int numbers[3] = {A, B, C};
    for (int num : numbers) {
      for (int i = 0; i < 3; i++) {
        int digit = num % 10;
        if (digit == 0 || (mask & (1 << digit))) {
          valid = false;
          break;
        }
        mask |= (1 << digit);
        num /= 10;
      }
      if (!valid)
        break;
    }
    if (valid && mask == 0b1111111110) { // mask应该包含1-9，即bits 1到9
      validTriplets.emplace_back(A, B, C);
    }
  }

  // 输出所有满足条件的三元组
  for (auto &[A, B, C] : validTriplets) {
    cout << A << " " << B << " " << C << endl;
  }

  return 0;
}
