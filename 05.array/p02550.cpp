#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n; // 买了几张彩票
    int levels[8];
    memset(levels,0,sizeof(levels)); // 初始化

    // 存放中奖的号码，保证不重复
    // 不校验号码在1-33
    set<int> win;
    for(int i=0;i<7;i++)
    {
        int x;
        cin>>x;
        win.insert(x);
    }
    for(int i=1;i<=n;i++)
    {
        int win_level=0;
        for(int c=1;c<=7;c++)
        {
            int x;
            cin >>x;
            if(win.count(x)) //在中奖号码中
            {
                win_level++;
            }
        }
        levels[win_level]++;
    }

    for(int i=7;i>=1;i--)
    {
        cout<<levels[i]<<" ";
    }

    return 0;
}