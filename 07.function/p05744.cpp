#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

int main()
{
    int n;
    cin >> n;
    vector<Student> s(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i].name >> s[i].age >> s[i].score;
    }

    for (auto x : s)
    {
        x.age++;
        x.score *= 1.2;
        if (x.score > 600)
        {
            x.score = 600;
        }
        cout << x.name << " " << x.age << " " << x.score << endl;
    }

    return 0;
}