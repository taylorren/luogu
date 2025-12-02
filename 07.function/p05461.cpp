#include <bits/stdc++.h>
using namespace std;

const int N = 1024+10;
int prisoners[N][N];

void solve(int x, int y, int size)
{
    if(size==1)
    {
        prisoners[x][y]=1;
        return;
    }

    size=size/2;
    solve(x, y+size, size);
    solve(x+size, y, size);
    solve(x+size, y+size, size);
}

int main()
{
    int n;
    cin>>n;
    int size=pow(2, n);

    solve(0, 0, size);

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            cout<<prisoners[i][j]<<" ";
        }
        cout<<endl;
    }
}