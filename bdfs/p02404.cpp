#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> path;

void print_path()
{
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i < path.size() - 1)
            cout << "+";
    }
    cout << endl;
}

void dfs(int remain, int last)
{
    if (remain == 0)
    {
        if (path.size() > 1)  // 确保至少拆分成两个数
        {
            print_path();
        }
        return;
    }

    for (int i = last; i < n && i <= remain; i++)  // 修改条件：i < n
    {
        path.push_back(i);
        dfs(remain - i, i);
        path.pop_back();
    }
}

int main()
{
    cin >> n;
    dfs(n, 1);
    return 0;
}