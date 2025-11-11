#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> sadness(n, 0);
    for(int i=0;i<n;i++)
    {
        cin>>sadness[i];
    }

    int min_sadness=0;
    for(int i=0;i<m;i++)
    {
        min_sadness+=sadness[i];
    } // The initial sadness is done
    
    int tmp=min_sadness;
    for(int i=m;i<n-1;i++)
    {
        tmp=tmp-sadness[i-m]+sadness[i];
        if(tmp<min_sadness)
        {
            min_sadness=tmp;
        }
    }

    cout<<min_sadness<<endl;

    return 0;
}