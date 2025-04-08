#include <bits/stdc++.h>
using namespace std;

struct Apple
{
    int height;  // 苹果高度
    int effort;  // 摘苹果需要的力气
};

bool cmp(const Apple& a, const Apple& b)
{
    return a.effort < b.effort;
}

int main()
{
    int n, s;  // 苹果数量和陶陶的力气
    cin >> n >> s;

    int chair, height;  // 椅子高度和手伸直的最大长度
    cin >> chair >> height;

    vector<Apple> apples;
    for (int i = 0; i < n; i++)
    {
        int x, y;  // 苹果高度和摘取需要的力气
        cin >> x >> y;

        // 只考虑能够摘到的苹果
        if (x <= chair + height)
        {
            apples.push_back({x, y});
        }
    }

    // 按照力气消耗从小到大排序
    sort(apples.begin(), apples.end(), cmp);

    int count = 0;  // 能摘到的苹果数量

    // 从力气消耗最小的苹果开始摘取
    for (const Apple& apple : apples)
    {
        if (s >= apple.effort)
        {
            s -= apple.effort;
            count++;
        }
        else
        {
            break;  // 力气不够，无法继续摘苹果
        }
    }

    cout << count << endl;

    return 0;
}