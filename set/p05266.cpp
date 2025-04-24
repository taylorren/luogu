#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 使用unordered_map存储学生信息，key为姓名，value为分数
    unordered_map<string, int> students;
    int op;
    string name;
    int score;

    for (int i = 1; i <= n; i++)
    {
        cin >> op;

        if (op == 1)
        {  // 插入或修改
            cin >> name >> score;
            students[name] = score;
            cout << "OK" << endl;
        }
        else if (op == 2)
        {  // 查询
            cin >> name;
            if (students.count(name))
            {
                cout << students[name] << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
        }
        else if (op == 3)
        {  // 删除
            cin>>name;
            if (students.count(name))
            {
                students.erase(name);
                cout << "Deleted successfully" << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
        }
        else if (op == 4)
        {  // 汇总
            cout << students.size() << endl;
        }
    }

    return 0;
}