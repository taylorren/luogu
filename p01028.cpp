#include <iostream>
#include <vector>
using namespace std;

// 记忆化搜索数组
vector<long long> memo;

// 计算以last为最后一个元素的合法数列的数量
long long count(int last)
{
    // 如果已经计算过，直接返回结果
    if (memo[last] != -1)
    {
        return memo[last];
    }

    // 初始化结果为1（表示只有last这一个元素的数列）
    long long result = 1;

    // 尝试在数列末尾添加1到⌊last/2⌋的任意整数
    for (int i = 1; i <= last / 2; i++)
    {
        result += count(i);
    }

    // 记忆化存储结果
    memo[last] = result;
    return result;
}

int main()
{
    int n;
    cin >> n;

    // 初始化记忆化数组
    memo.resize(n + 1, -1);

    // 计算结果
    long long answer = count(n);

    cout << answer << endl;

    return 0;
}
