#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin>>m>>n;

    vector<int> digits(10, 0);
    for(int i=m; i<=n; i++)
    {
        int num = i;
        while(num)
        {
            digits[num%10]++;
            num /= 10;
        }
    }

    for(auto d:digits)
    {
        cout<<d<<" ";
    }
    return 0;
}