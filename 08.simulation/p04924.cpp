#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int matrix[MAXN][MAXN];
int temp[MAXN][MAXN];

// 顺时针旋转以(x,y)为中心，半径为r的矩阵
void rotateClockwise(int x, int y, int r)
{
    // 先将要旋转的部分复制到临时数组
    for (int i = x - r; i <= x + r; i++)
    {
        for (int j = y - r; j <= y + r; j++)
        {
            temp[i][j] = matrix[i][j];
        }
    }

    // 进行顺时针旋转
    for (int i = x - r; i <= x + r; i++)
    {
        for (int j = y - r; j <= y + r; j++)
        {
            // 计算相对于中心的坐标
            int dx = i - x;
            int dy = j - y;
            // 顺时针旋转90度：(dx, dy) -> (dy, -dx)
            matrix[x + dy][y - dx] = temp[i][j];
        }
    }
}

// 逆时针旋转以(x,y)为中心，半径为r的矩阵
void rotateCounterClockwise(int x, int y, int r)
{
    // 先将要旋转的部分复制到临时数组
    for (int i = x - r; i <= x + r; i++)
    {
        for (int j = y - r; j <= y + r; j++)
        {
            temp[i][j] = matrix[i][j];
        }
    }

    // 进行逆时针旋转
    for (int i = x - r; i <= x + r; i++)
    {
        for (int j = y - r; j <= y + r; j++)
        {
            // 计算相对于中心的坐标
            int dx = i - x;
            int dy = j - y;
            // 逆时针旋转90度：(dx, dy) -> (-dy, dx)
            matrix[x - dy][y + dx] = temp[i][j];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // 初始化矩阵，按照从左往右，从上至下的顺序填入1到n^2
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            matrix[i][j] = num++;
        }
    }

    // 执行m次魔法操作
    for (int i = 0; i < m; i++)
    {
        int x, y, r, z;
        cin >> x >> y >> r >> z;

        if (z == 0)
        {
            // 顺时针旋转
            rotateClockwise(x, y, r);
        }
        else
        {
            // 逆时针旋转
            rotateCounterClockwise(x, y, r);
        }
    }

    // 输出最终矩阵
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << matrix[i][j];
            if (j < n)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}