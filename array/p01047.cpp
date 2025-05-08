#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, m;
    cin >> l >> m;
    
    // 初始化，所有位置都有树
    vector<bool> hasTree(l + 1, true);
    
    // 处理每个区域
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        
        // 将区域内的树标记为已移除
        for (int j = start; j <= end; j++) {
            hasTree[j] = false;
        }
    }
    
    // 统计剩余的树木数量
    int count = 0;
    for (int i = 0; i <= l; i++) {
        if (hasTree[i]) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}