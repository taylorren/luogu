#include <iostream>
#include <string>
using namespace std;

// 计算字符串中VK的数量
int countVK(const string& s)
{
    int count = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == 'V' && s[i + 1] == 'K')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int maxCount = countVK(s);  // 原始字符串中VK的数量

    // 尝试修改每个位置
    for (int i = 0; i < n; i++)
    {
        string temp = s;
        // 尝试改成另一个字符
        temp[i] = (temp[i] == 'V' ? 'K' : 'V');
        maxCount = max(maxCount, countVK(temp));
    }

    cout << maxCount << endl;
    return 0;
}