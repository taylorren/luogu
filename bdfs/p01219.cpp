#include <iostream>
using namespace std;

const int MAXN = 20;
int n;
int ans[MAXN];  // 存储每行皇后的列位置
int count = 0;  // 解的总数

void print_solution()
{
    count++;
    if (count <= 3)
    {
        for (int i = 1; i <= n; i++)
        {                           // 修改循环范围
            cout << ans[i] << " ";  // 不需要+1，因为我们直接存储1-based的值
        }
        cout << endl;
    }
}

bool check(int row, int col)
{
    for (int i = 1; i < row; i++)
    {
        if (ans[i] == col ||                    // 同列
            abs(row - i) == abs(col - ans[i]))  // 对角线
            return false;
    }
    return true;
}

void solve(int row)
{
    if (row > n)
    {  // 修改终止条件
        print_solution();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (check(row, i))
        {
            ans[row] = i;
            solve(row + 1);
            ans[row] = 0;  // 回溯
        }
    }
}

int main()
{
    cin >> n;
    solve(1);  // 从1开始
    cout << count << endl;
    return 0;
}