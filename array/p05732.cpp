#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 创建二维数组存储杨辉三角
    vector<vector<int>> triangle(n, vector<int>(n, 0));
    
    // 生成杨辉三角
    for (int i = 0; i < n; i++) {
        // 每行的第一个数字都是1
        triangle[i][0] = 1;
        
        // 计算每行中间的数字
        for (int j = 1; j <= i; j++) {
            // 当前位置的值等于上一行中相邻两个数字的和
            if (j == i) {
                // 每行的最后一个数字也是1
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
        
        // 输出当前行
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j];
            if (j < i) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}