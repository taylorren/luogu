#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 用vector存储变换序列
    vector<int> sequence;
    sequence.push_back(n);
    
    // 按照冰雹猜想规则进行变换
    while (n != 1) {
        if (n % 2 == 1) {
            // 奇数：乘3加1
            n = n * 3 + 1;
        } else {
            // 偶数：除以2
            n = n / 2;
        }
        sequence.push_back(n);
    }
    
    // 倒序输出序列
    for (int i = sequence.size() - 1; i >= 0; i--) {
        cout << sequence[i];
        if (i > 0) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}