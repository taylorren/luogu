#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;

struct Volunteer
{
    string id;
    int score;
};

bool cmp(Volunteer &a, Volunteer &b)
{
    if(a.score==b.score)
    {
        return a.id<b.id;
    }
    else
    {
        return a.score>b.score;
    }
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;

    vector<Volunteer> volunteers;

    for(int i=1;i<=n;i++)
    {
        string tmp_id;
        int tmp_score;

        cin>>tmp_id>>tmp_score;
        Volunteer v;
        v.id=tmp_id;
        v.score=tmp_score;

        volunteers.push_back(v);
    }

    sort(volunteers.begin(), volunteers.end(), cmp);
    
    int lowest_index=floor(1.5*m);
    int lowest_score=volunteers.at(lowest_index-1).score;

    //cout<<lowest_index<<" "<<lowest_score<<endl;

    int count=0;
    for(auto& v:volunteers)
    {
        if(v.score>=lowest_score)
        {
            count++;
        }
    }

    cout<<lowest_score<<" "<<count<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<volunteers[i].id<<" "<<volunteers[i].score<<endl;
    }

    return 0;
}