#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int chinese, math, english;
};

int main()
{
    int n;
    cin >> n;

    Student stu;
    stu.chinese = -1;
    stu.math = -1;
    stu.english = -1;

    for (int i = 1; i <= n; i++)
    {
        string name;
        int chinese, math, english;
        cin >> name >> chinese >> math >> english;

        if (chinese + math + english > stu.chinese + stu.math + stu.english)
        {
            stu.name = name;
            stu.chinese = chinese;
            stu.math = math;
            stu.english = english;
        }
    }

    cout << stu.name << " " << stu.chinese << " " << stu.math << " "
         << stu.english << endl;

    return 0;
}