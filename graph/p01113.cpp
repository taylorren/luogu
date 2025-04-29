#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Task
{
    int duration;
    vector<int> pre_tasks;
};

const int MAXN = 10005;
Task tasks[MAXN];
int dp[MAXN];  // dp[i]表示完成任务i的最早时间

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        int id, len, pre;
        cin >> id >> len;
        tasks[id].duration = len;

        while (cin >> pre && pre != 0)
        {
            tasks[id].pre_tasks.push_back(pre);
        }
    }

    int max_time = 0;
    for (int i = 1; i <= n; ++i) 
    {
        int current_max = 0;
        for (int pre : tasks[i].pre_tasks) 
        {
            current_max = max(current_max, tasks[pre].duration);
        }
        tasks[i].duration += current_max;
        max_time = max(max_time, tasks[i].duration);
    }
    cout << max_time << endl;

    return 0;
}