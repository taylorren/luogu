#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 创建n×n的矩阵，初始化为0
    vector<vector<int>> magic_square(n, vector<int>(n, 0));
    
    // 将1放在第一行中间
    int row = 0;
    int col = n / 2;
    magic_square[row][col] = 1;
    
    // 依次填入2到n×n的数字
    for (int k = 2; k <= n * n; k++) {
        // 记录前一个数的位置
        int prev_row = row;
        int prev_col = col;
        
        // 根据规则确定当前数的位置
        if (prev_row == 0 && prev_col != n - 1) {
            // 规则1：前一个数在第一行但不在最后一列
            row = n - 1;
            col = prev_col + 1;
        } else if (prev_row != 0 && prev_col == n - 1) {
            // 规则2：前一个数在最后一列但不在第一行
            row = prev_row - 1;
            col = 0;
        } else if (prev_row == 0 && prev_col == n - 1) {
            // 规则3：前一个数在第一行最后一列
            row = prev_row + 1;
            col = prev_col;
        } else {
            // 规则4：前一个数既不在第一行也不在最后一列
            int next_row = prev_row - 1;
            int next_col = prev_col + 1;
            
            if (next_row >= 0 && next_col < n && magic_square[next_row][next_col] == 0) {
                // 右上方为空
                row = next_row;
                col = next_col;
            } else {
                // 右上方已填数或超出边界，填在正下方
                row = prev_row + 1;
                col = prev_col;
            }
        }
        
        // 填入当前数
        magic_square[row][col] = k;
    }
    
    // 输出幻方
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magic_square[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}