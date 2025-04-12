#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        cout<<v[x-1]<<endl;
    }

    return 0;
}