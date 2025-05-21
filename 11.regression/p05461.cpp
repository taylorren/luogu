#include <iostream>
using namespace std;

int matrix[1024][1024];

void solve(int x, int y, int size)
{
    if (size == 1)
    {
        matrix[x][y] = 1;  // 到达最小单位，标记为不赦免
        return;
    }

    int new_size = size / 2;
    solve(x, y + new_size, new_size);             // 右上
    solve(x + new_size, y, new_size);             // 左下
    solve(x + new_size, y + new_size, new_size);  // 右下
}

int main()
{
    int n;
    cin >> n;
    int size = 1 << n;

    // 初始化矩阵，全部设为0（赦免）
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
    }

    solve(0, 0, size);

    // 输出结果
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j];
            if (j < size - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}