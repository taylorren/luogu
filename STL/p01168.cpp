#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long sum = 0;
    multiset<int> prev_values;
    
    for (int i = 0; i < n; i++) {
        int current;
        cin >> current;
        
        if (i == 0) {
            // 第一天的最小波动值为第一天的营业额
            sum += current;
        } else {
            // 找到与当前营业额差值最小的前一天营业额
            int min_diff = INT_MAX;
            
            // 使用lower_bound找到大于等于current的第一个元素
            auto it = prev_values.lower_bound(current);
            
            // 检查这个元素
            if (it != prev_values.end()) {
                min_diff = min(min_diff, abs(*it - current));
            }
            
            // 检查前一个元素（如果存在）
            if (it != prev_values.begin()) {
                it--;
                min_diff = min(min_diff, abs(*it - current));
            }
            
            sum += min_diff;
        }
        
        // 将当前营业额添加到集合中
        prev_values.insert(current);
    }
    
    cout << sum << endl;
    return 0;
}