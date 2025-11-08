#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, m; //马路长度，区间个数
    cin >> l >> m;

    vector<bool> trees(l+1, true); //这个长度区间上都有树：true

    for(int i=1;i<=m;i++)
    {
        int s, e; //各个区间的起始
        cin>>s>>e;
        for(int j=s;j<=e;j++)
        {
            trees[j] = false;
        }
    }

    int count = 0;
    for(int i=0;i<=l;i++)
    {
        if(trees[i])
            count++;
    }
    cout << count << endl;

    return 0;
}