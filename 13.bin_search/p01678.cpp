#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> schools(m);
    vector<int> students(n);

    // 输入学校分数线
    for (int i = 0; i < m; ++i) {
        cin >> schools[i];
    }

    // 输入学生估分
    for (int i = 0; i < n; ++i) {
        cin >> students[i];
    }

    // 排序学校分数线
    sort(schools.begin(), schools.end());

    // 计算最小不满意度
    long long total_dissatisfaction = 0; // 使用 long long 防止溢出

    for (int i = 0; i < n; ++i) {
        int student_score = students[i];

        // 使用二分查找找到最接近的学校分数线
        auto it = lower_bound(schools.begin(), schools.end(), student_score);

        // 计算不满意度
        int dissatisfaction = INT_MAX;

        // 比较二分查找结果的左右两侧
        if (it != schools.end()) {
            dissatisfaction = abs(*it - student_score);
        }
        if (it != schools.begin()) {
            dissatisfaction = min(dissatisfaction, abs(*(it - 1) - student_score));
        }

        total_dissatisfaction += dissatisfaction;
    }

    // 输出最小不满意度总和
    cout << total_dissatisfaction << endl;

    return 0;
}