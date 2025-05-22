#include <cmath>
#include <iostream>
using namespace std;

const int MAXN = 15;
int n;
int s[MAXN], b[MAXN];  // 每种食材的酸度和苦度
int min_diff = 1e9;    // 最小差值

void dfs(int pos, int sour, int bitter, bool selected)
{
    // 已经处理完所有食材
    if (pos == n)
    {
        // 至少选择了一种食材
        if (selected)
        {
            min_diff = min(min_diff, abs(sour - bitter));
        }
        return;
    }

    // 选择当前食材
    dfs(pos + 1, sour * s[pos], bitter + b[pos], true);
    // 不选择当前食材
    dfs(pos + 1, sour, bitter, selected);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> b[i];
    }

    dfs(0, 1, 0, false);  // 初始酸度为1（乘法），苦度为0（加法）
    cout << min_diff << endl;

    return 0;
}