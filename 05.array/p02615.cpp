#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n; //N阶幻方，必须是奇数
    assert(n%2==1);
    int a[40][40];
    memset(a,0,sizeof(a));
    
    int x=1, y=(n+1)/2; // 起始位置
    a[x][y]=1;

    for(int k=2;k<=n*n;k++)
    {
        if(x==1 && y!=n) //第一行但不最后一列
        {
            a[n][y+1]=k;
            x=n; y++;
        }
        else if(x!=1 && y==n) //第一列但不最后一行
        {
            a[x-1][1]=k;
            x--, y=1;
        }
        else if(x!=1 && y==n) //最后一列但不是第一行
        {
            a[x-1][1]=k;
            x--, y=1;
        }
        else if(x==1&&y==n) //最后一行最后一列
        {
            a[x+1][y]=k;
            x++;
        }
        else if (x!=1 && y!=n)
        {
            if(a[x-1][y+1]==0) //右上方空，填到右上方
            {
                a[x-1][y+1]=k;
                x--, y++;
            }
            else //否则正下方
            {
                a[x+1][y]=k;
                x++;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}