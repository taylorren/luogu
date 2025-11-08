#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=0, tmp, num[101];

    do
    {
        cin>>tmp;
        num[n]=tmp;
        n++;
    }while(tmp!=0);

    n--;
    for(int i=n-1;i>=0;i--)
    {
        cout<<num[i]<<" ";
    }

    return 0;
}