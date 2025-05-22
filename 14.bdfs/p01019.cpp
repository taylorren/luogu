#include <bits/stdc++.h>
using namespace std;

const int MAXN = 21;
int n;               // 单词数量
string words[MAXN];  // 存储单词
int used[MAXN];      // 记录每个单词使用次数
int ans = 0;         // 最长龙的长度
char start;          // 开始字母

// 检查两个单词能否相连，返回重叠部分长度
int check(const string& s1, const string& s2)
{
    int len1 = s1.length();
    int len2 = s2.length();

    // 找到最长的重叠部分
    for (int i = 1; i < min(len1, len2); i++)
    {
        bool match = true;
        // 检查s1的末尾i个字符是否与s2的开头i个字符匹配
        for (int j = 0; j < i; j++)
        {
            if (s1[len1 - i + j] != s2[j])
            {
                match = false;
                break;
            }
        }
        // 确保不存在包含关系
        if (match && i != len2 && i != len1)
        {
            return i;
        }
    }
    return 0;
}

// DFS搜索
// cur: 当前龙的最后一个单词的索引
// len: 当前龙的长度
void dfs(int cur, int len)
{
    ans = max(ans, len);

    // 尝试接上每个单词
    for (int i = 0; i < n; i++)
    {
        // 如果单词已使用两次，跳过
        if (used[i] >= 2)
            continue;

        int overlap = 0;
        if (cur == -1)
        {
            // 如果是第一个单词，检查是否以指定字母开头
            if (words[i][0] != start)
                continue;
            overlap = 0;
        }
        else
        {
            // 检查是否能接上
            overlap = check(words[cur], words[i]);
            if (overlap == 0)
                continue;
        }

        // 使用这个单词
        used[i]++;
        dfs(i, len + words[i].length() - overlap);
        used[i]--;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    cin >> start;

    dfs(-1, 0);
    cout << ans << endl;

    return 0;
}