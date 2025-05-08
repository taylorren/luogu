#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 存储每个学生的三科成绩
    vector<vector<int>> scores(n, vector<int>(3));

    // 读取每个学生的成绩
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i][0] >> scores[i][1] >> scores[i][2];
    }

    int count = 0;  // 记录旗鼓相当的对手对数

    // 检查每一对学生
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // 检查每科分差是否都不大于5
            bool isComparable = true;
            for (int k = 0; k < 3; k++)
            {
                if (abs(scores[i][k] - scores[j][k]) > 5)
                {
                    isComparable = false;
                    break;
                }
            }

            // 如果每科分差都不大于5，再检查总分分差
            if (isComparable)
            {
                int totalI = scores[i][0] + scores[i][1] + scores[i][2];
                int totalJ = scores[j][0] + scores[j][1] + scores[j][2];

                if (abs(totalI - totalJ) <= 10)
                {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}