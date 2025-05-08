#include <bits/stdc++.h>
using namespace std;

// 顺时针旋转90度
vector<vector<char>> rotate90(const vector<vector<char>>& matrix, int n)
{
    vector<vector<char>> result(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[j][n - 1 - i] = matrix[i][j];
        }
    }
    return result;
}

// 水平反射
vector<vector<char>> reflect(const vector<vector<char>>& matrix, int n)
{
    vector<vector<char>> result(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][n - 1 - j] = matrix[i][j];
        }
    }
    return result;
}

// 检查两个矩阵是否相等
bool isEqual(const vector<vector<char>>& matrix1,
             const vector<vector<char>>& matrix2, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    // 读取初始矩阵
    vector<vector<char>> original(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> original[i][j];
        }
    }

    // 读取目标矩阵
    vector<vector<char>> target(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> target[i][j];
        }
    }

    // 尝试各种转换方式

    // 1. 顺时针旋转90°
    vector<vector<char>> rotated90 = rotate90(original, n);
    if (isEqual(rotated90, target, n))
    {
        cout << 1 << endl;
        return 0;
    }

    // 2. 顺时针旋转180°
    vector<vector<char>> rotated180 = rotate90(rotated90, n);
    if (isEqual(rotated180, target, n))
    {
        cout << 2 << endl;
        return 0;
    }

    // 3. 顺时针旋转270°
    vector<vector<char>> rotated270 = rotate90(rotated180, n);
    if (isEqual(rotated270, target, n))
    {
        cout << 3 << endl;
        return 0;
    }

    // 4. 水平反射
    vector<vector<char>> reflected = reflect(original, n);
    if (isEqual(reflected, target, n))
    {
        cout << 4 << endl;
        return 0;
    }

    // 5. 组合转换
    // 5.1 水平反射 + 旋转90°
    vector<vector<char>> reflectedRotated90 = rotate90(reflected, n);
    if (isEqual(reflectedRotated90, target, n))
    {
        cout << 5 << endl;
        return 0;
    }

    // 5.2 水平反射 + 旋转180°
    vector<vector<char>> reflectedRotated180 = rotate90(reflectedRotated90, n);
    if (isEqual(reflectedRotated180, target, n))
    {
        cout << 5 << endl;
        return 0;
    }

    // 5.3 水平反射 + 旋转270°
    vector<vector<char>> reflectedRotated270 = rotate90(reflectedRotated180, n);
    if (isEqual(reflectedRotated270, target, n))
    {
        cout << 5 << endl;
        return 0;
    }

    // 6. 不改变
    if (isEqual(original, target, n))
    {
        cout << 6 << endl;
        return 0;
    }

    // 7. 无效转换
    cout << 7 << endl;

    return 0;
}