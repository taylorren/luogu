#include <bits/stdc++.h>
using namespace std;

struct Candidate
{
    int id;
    string votes;
};

bool cmp(const Candidate& a, const Candidate& b)
{
    if (a.votes.length() != b.votes.length())
    {
        return (a.votes.length() > b.votes.length());
    }
    else  // 长度相等的字符串，进行字典序比较
    {
        return a.votes > b.votes;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<Candidate> candidates(n);
    for (int i = 0; i < n; i++)
    {
        string votes;
        cin >> votes;
        candidates[i].id = i + 1;
        candidates[i].votes = votes;
    }

    sort(candidates.begin(), candidates.end(), cmp);

    cout << candidates[0].id << endl;
    cout << candidates[0].votes << endl;

    return 0;
}