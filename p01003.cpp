#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<pair<int, int>, pair<int, int>>> carpets(n); // (a, b), (g, k)

  for (int i = 0; i < n; ++i) {
    int a, b, g, k;
    cin >> a >> b >> g >> k;
    carpets[i] = {{a, b}, {g, k}};
  }

  int x, y;
  cin >> x >> y;

  // 从最后一张地毯开始检查
  for (int i = n - 1; i >= 0; --i) {
    int a = carpets[i].first.first;
    int b = carpets[i].first.second;
    int g = carpets[i].second.first;
    int k = carpets[i].second.second;

    if (a <= x && x <= a + g && b <= y && y <= b + k) {
      cout << (i + 1) << endl; // 输出地毯编号，编号从1开始
      return 0;
    }
  }

  cout << -1 << endl; // 没有地毯覆盖
  return 0;
}