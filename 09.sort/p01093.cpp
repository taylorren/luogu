#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int id;
    int chinese, math, english;
    int total;
};

bool cmp(const Student& a, const Student& b)
{
    if (a.total != b.total)
    {
        return a.total > b.total;
    }
    else if (a.chinese != b.chinese)
    {
        return a.chinese > b.chinese;
    }
    else
    {
        return a.id < b.id;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Student> s(n);

    for (int i = 0; i < n; i++)
    {
        int c, m, e;
        cin >> c >> m >> e;

        s[i].id = i + 1;
        s[i].chinese = c;
        s[i].math = m;
        s[i].english = e;
        s[i].total = c + m + e;
    }

    sort(s.begin(), s.end(), cmp);

    for (int i = 0; i < 5; i++)
    {
        cout << s[i].id << ' ' << s[i].total << endl;
    }

    return 0;
}