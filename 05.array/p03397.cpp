#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for(int i=0; i<m; i++)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        for(int j=x1; j<=x2; j++)
        {
            for(int k=y1; k<=y2; k++)
            {
                v[j-1][k-1]++;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}