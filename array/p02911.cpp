#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    // 创建数组来存储每个和出现的次数
    // 最大可能的和是s1+s2+s3，所以数组大小为s1+s2+s3+1
    vector<int> count(s1 + s2 + s3 + 1, 0);

    // 枚举所有可能的骰子组合
    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            for (int k = 1; k <= s3; k++)
            {
                int sum = i + j + k;
                count[sum]++;
            }
        }
    }

    // 找出出现次数最多的和
    int max_count = 0;
    int result = 0;

    for (int sum = 3; sum <= s1 + s2 + s3; sum++)
    {
        if (count[sum] > max_count)
        {
            max_count = count[sum];
            result = sum;
        }
    }

    cout << result << endl;

    return 0;
}