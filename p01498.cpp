#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// 递归绘制分形三角形
void drawTriangle(vector<vector<char>>& grid, int r, int c, int size)
{
    if (size == 1)
    {
        // 绘制基本三角形
        grid[r][c] = '/';
        grid[r][c + 1] = '\\';
        grid[r + 1][c - 1] = '/';
        grid[r + 1][c] = '_';
        grid[r + 1][c + 1] = '_';
        grid[r + 1][c + 2] = '\\';
        return;
    }

    // 递归绘制小三角形
    int newSize = size / 2;
    // 上方三角形
    drawTriangle(grid, r, c, newSize);
    // 左下方三角形
    drawTriangle(grid, r + newSize * 2, c - newSize * 2, newSize);
    // 右下方三角形
    drawTriangle(grid, r + newSize * 2, c + newSize * 2, newSize);
}

int main()
{
    int n;
    cin >> n;

    // 计算网格大小
    int size = pow(2, n - 1);
    int height = size * 2;
    int width = size * 4;

    // 初始化网格，用空格填充
    vector<vector<char>> grid(height, vector<char>(width, ' '));

    // 绘制三角形
    drawTriangle(grid, 0, width / 2 - 1, size);

    // 输出结果
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}