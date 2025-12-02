#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int chinese, math, english;

    Student() : name(""), chinese(0), math(0), english(0) {}
    Student(string n, int c, int m, int e)
        : name(n), chinese(c), math(m), english(e)
    {
    }
    int getTotal() const
    {
        return chinese + math + english;
    }
    bool checkDiff(int a, int b, int range) const
    {
        return abs(a - b) <= range;
    }

    bool operator==(const Student& a) const
    {
        if (checkDiff(a.chinese, chinese, 5) && checkDiff(a.math, math, 5) &&
            checkDiff(a.english, english, 5) &&
            checkDiff(getTotal(), a.getTotal(), 10))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

Student students[1000 + 10];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string name;
        int chinese, math, english;
        cin >> name >> chinese >> math >> english;
        students[i] = Student(name, chinese, math, english);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (students[i] == students[j])
            {
                cout << students[i].name << " " << students[j].name << endl;
            }
        }
    }

    return 0;
}