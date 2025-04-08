#include <bits/stdc++.h>
using namespace std;

struct Contest
{
    int start;
    int end;
};

bool cmp(Contest &a, Contest &b)
{
    return a.end < b.end;
}

int main()
{
    int n;
    cin >> n;
    vector<Contest> contests(n);
    for (int i = 0; i < n; i++)
    {
        cin >> contests[i].start >> contests[i].end;
    }

    sort(contests.begin(), contests.end(), cmp);

    int ans = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        if (contests[i].start >= end)
        {
            ans++;
            end = contests[i].end;
        }
    }

    cout << ans << endl;

    return 0;
}