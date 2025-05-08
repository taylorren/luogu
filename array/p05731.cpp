#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 创建n×n的矩阵
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    // 特殊处理n=1的情况
    if (n == 1) {
        matrix[0][0] = 1;
    } else {
        int num = 1;           // 从1开始填充
        int row = 0, col = 0;  // 当前位置
        int layer = 0;         // 当前层数

        // 填充矩阵直到所有位置都被填满
        while (num <= n * n)
        {
            // 向右填充
            while (col < n - layer - 1)
            {
                matrix[row][col] = num++;
                col++;
            }

            // 向下填充
            while (row < n - layer - 1)
            {
                matrix[row][col] = num++;
                row++;
            }

            // 向左填充
            while (col > layer)
            {
                matrix[row][col] = num++;
                col--;
            }

            // 向上填充
            while (row > layer)
            {
                matrix[row][col] = num++;
                row--;
            }

            // 填充完一层后，向内层移动
            layer++;
            row = layer;
            col = layer;

            // 如果n是奇数，最后中心位置需要单独处理
            if (layer == n / 2 && n % 2 == 1)
            {
                matrix[row][col] = num++;
            }
        }
    }

    // 输出矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 每个数字占用3个字符，不足的用空格补齐
            printf("%3d", matrix[i][j]);
        }
        cout << endl;
    }

    return 0;
}