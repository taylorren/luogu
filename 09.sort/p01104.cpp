#include <bits/stdc++.h>
using namespace std;

// 定义学生结构体
struct Student {
    string name;
    int year, month, day;
    int index; // 记录输入顺序，用于处理生日相同的情况
};

// 比较函数：按生日从大到小排序
bool compareByBirthday(const Student &a, const Student &b) {
    // 先比较年
    if (a.year != b.year) {
        return a.year < b.year; // 年份小的年龄大
    }
    // 年相同，比较月
    if (a.month != b.month) {
        return a.month < b.month; // 月份小的年龄大
    }
    // 年月相同，比较日
    if (a.day != b.day) {
        return a.day < b.day; // 日期小的年龄大
    }
    // 生日完全相同，按输入顺序的逆序排列
    return a.index > b.index; // 输入靠后的先输出
}

int main() {
    int n;
    cin >> n;
    
    vector<Student> students(n);
    
    // 读取输入
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].year >> students[i].month >> students[i].day;
        students[i].index = i; // 记录输入顺序
    }
    
    // 按生日从大到小排序
    sort(students.begin(), students.end(), compareByBirthday);
    
    // 输出结果
    for (const auto &student : students) {
        cout << student.name << endl;
    }
    
    return 0;
}