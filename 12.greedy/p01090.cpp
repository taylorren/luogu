#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 从文件读取输入（如果需要）
    //freopen("p01090_2.in", "r", stdin);
    
    int n, n2=0;
    cin >> n;
    
    // 使用vector替代数组
    vector<int> w1(n+10);
    vector<int> w2(n+10);
    
    // 初始化w2为一个大值，但不是INT_MAX
    int bigValue = 0x7F7F7F7F;  // 与memset(w1, 127, sizeof(w1))相同的值
    fill(w1.begin(), w1.end(), bigValue);
    fill(w2.begin(), w2.end(), bigValue);
    
    int sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> w1[i];
    }

    sort(w1.begin(), w1.begin() + n);
    int i = 0, j = 0, k, w;

    for(k = 1; k < n; k++) {
        w = w1[i] < w2[j] ? w1[i++] : w2[j++]; // 取w1[i]和w2[j]中较小的一个
        w += w1[i] < w2[j] ? w1[i++] : w2[j++]; // 取w1[i]和w2[j]中较小的第二个
        w2[n2++] = w;
        sum += w;
    }

    cout << sum << endl;
    return 0;
}