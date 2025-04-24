#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin>>n;


    map<int,int> positions;
    for(int i=0;i<n;i++)
    {
        int balls;
        cin>>balls;
        positions[balls] = i;
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int hit;
        cin>>hit;
        if(positions.find(hit)!=positions.end())
        {
            cout<<positions[hit]+1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }

    return 0;
}