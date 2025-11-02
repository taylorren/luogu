#include <bits/stdc++.h>
using namespace std;

struct Position
{
    int num;
    int time;
};

bool cmp(Position a, Position b)
{
    if(a.time!=b.time)
    {
        return a.time<b.time;
    }
    return a.num<b.num;
}

int main()
{
    int n;
    cin >> n;
    long long total=0;
    vector<Position> positions(n);
    for (int i = 0; i < n; i++)
    {
        cin>>positions[i].time;
        positions[i].num=i+1;
    }

    sort(positions.begin(),positions.end(),cmp);
    for(int i=0;i<n;i++)
    {
        cout<<positions[i].num<<" ";
        total+=positions[i].time*(n-i-1);
    }
    cout<<endl;
    
    cout<<fixed<<setprecision(2)<<1.0*total/n<<endl;

    return 0;
}