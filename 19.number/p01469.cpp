#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int result = 0;
    for (int i = 0; i < n; i++) {
        int length;
        scanf("%d", &length);
        result ^= length;  // 使用异或运算
    }
    
    cout << result << endl;
    return 0;
}