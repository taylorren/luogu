#include <bits/stdc++.h>
using namespace std;

int fingers[10010];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> fingers[i];
  }

  while (m--) {
    next_permutation(fingers + 1, fingers + n + 1);
  }

  for (int i = 1; i <= n; i++) {
    cout << fingers[i] << " ";
  }
  cout << endl;

  return 0;
}
