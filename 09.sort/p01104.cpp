#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int y, m, d;
    int index;
};

bool cmp(const Student& a, const Student& b)
{
    if (a.y != b.y)
    {
        return a.y < b.y;
    }
    if (a.m != b.m)
    {
        return a.m < b.m;
    }
    if (a.d != b.d)
    {
        return a.d < b.d;
    }

    return a.index > b.index;
}

int main()
{
    // freopen("P1104_6.in", "r", stdin);
    // freopen("P1104_6.out", "w", stdout);
    int n;
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; i++)
    {
        cin >> students[i].name;
        cin >> students[i].y;
        cin >> students[i].m;
        cin >> students[i].d;
        students[i].index = i;
    }

    sort(students.begin(), students.end(), cmp);

    for (auto s : students)
    {
        cout << s.name << endl;
    }

    return 0;
}