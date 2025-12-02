#include <bits/stdc++.h>
using namespace std;
struct Student
{
    int id;        // 学号
    int sc1, sc2;  // 学业成绩和素质拓展成绩

    double final_score;  // 综合分数

    int sum()
    {
        return sc1 + sc2;  // 返回学业成绩和素质拓展成绩的和
    }
};

const int SCORE = 140;
const int FINAL = 80;

bool isExcellent(Student s)
{
    return s.sum() > SCORE && s.final_score >= FINAL;
}

int main()
{
    int n;
    cin >> n;
    Student s;  // 定义一个结构体数组
    for (int i = 0; i < n; i++)
    {
        cin >> s.id >> s.sc1 >> s.sc2;
        s.final_score = s.sc1 * 0.7 + s.sc2 * 0.3;  // 计算综合分数

        if (isExcellent(s))
        {
            cout << "Excellent" << endl;
        }
        else
        {
            cout << "Not excellent" << endl;
        }
    }
    return 0;
}