#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    // 创建一个数组来存储每个数字（0-9）出现的次数
    int count[10] = {0};

    // 遍历从M到N的每个数
    for (int i = M; i <= N; i++)
    {
        // 将当前数字转换为字符串
        string num_str = to_string(i);

        // 统计当前数字中每个数位的出现次数
        for (char digit : num_str)
        {
            count[digit - '0']++;
        }
    }

    // 输出结果
    for (int i = 0; i < 10; i++)
    {
        cout << count[i];
        if (i < 9)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}