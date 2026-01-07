#include <bits/stdc++.h>
using namespace std;

struct Volunteer
{
    string id;
    int score;
};

bool cmp(const Volunteer& a, const Volunteer& b)
{
    if (a.score != b.score)
    {
        return (a.score >= b.score);
    }
    else
    {
        return (a.id < b.id);
    }
}

int main()
{
    int n, total;
    cin >> n >> total;
    vector<Volunteer> v(n);
    for (int i = 0; i < n; i++)
    {
        string id;
        int score;
        cin >> id >> score;
        v[i].id = id;
        v[i].score = score;
    }

    sort(v.begin(), v.end(), cmp);
    int low_index = floor(total * 1.5);
    int low_score = v.at(low_index - 1).score;

    int count = 0;
    for (auto vv : v)
    {
        if (vv.score >= low_score)
        {
            count++;
        }
    }

    cout << low_score << " " << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << v[i].id << " " << v[i].score << endl;
    }
}