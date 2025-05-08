#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 读取中奖号码
    vector<int> winning_numbers(7);
    for (int i = 0; i < 7; i++)
    {
        cin >> winning_numbers[i];
    }

    // 使用布尔数组标记中奖号码，而不是set
    bool is_winning[34] = {false};  // 号码范围是1-33，所以用34大小的数组
    for (int i = 0; i < 7; i++)
    {
        is_winning[winning_numbers[i]] = true;
    }

    // 初始化各奖项的中奖张数
    vector<int> prize_counts(7, 0);  // 索引0对应特等奖，索引6对应六等奖

    // 处理每张彩票
    for (int i = 0; i < n; i++)
    {
        int match_count = 0;

        // 读取一张彩票的7个号码
        for (int j = 0; j < 7; j++)
        {
            int ticket_number;
            cin >> ticket_number;

            // 检查是否匹配中奖号码
            if (is_winning[ticket_number])
            {
                match_count++;
            }
        }

        // 根据匹配数量更新奖项计数
        if (match_count > 0)
        {
            prize_counts[7 - match_count]++;  // 7-match_count是奖项索引
        }
    }

    // 输出结果
    for (int i = 0; i < 7; i++)
    {
        cout << prize_counts[i];
        if (i < 6)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}