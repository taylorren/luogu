#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
int main()
{
    int ans=0;
    char a[MAXN], b[MAXN];
    cin >> a >> b;
    for(int i=0;a[i]; i++)
    {
        for(int j=1;b[j];j++)
        {
            if(a[i]==b[j]&&a[i+1]==b[j-1])
            {
                ans++;
            }
        }
    }

    cout<<(1<<ans)<<endl;
    return 0;

}