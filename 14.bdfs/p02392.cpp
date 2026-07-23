#include <bits/stdc++.h>
using namespace std;

const int N = 4 + 1;
int exercises_in_subject[N];
int exercises_time[N][21];  // max 20 exercises per subject

void dfs(int subject, int exercise, int left, int right, int &total_time)
{
    if (exercise > exercises_in_subject[subject])
    {
        total_time = min(total_time, max(left, right));
        return;
    }
    dfs(subject, exercise + 1, left + exercises_time[subject][exercise], right,
        total_time);  // 左脑练习
    dfs(subject, exercise + 1, left, right + exercises_time[subject][exercise],
        total_time);  // 右脑练习
}

int solve(int subject)
{
    int min_time = 1e9;
    dfs(subject, 1, 0, 0, min_time);
    return min_time;
}
int main()
{
    for (int i = 1; i <= N - 1; i++)
    {
        cin >> exercises_in_subject[i];
    }
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 1; j <= exercises_in_subject[i]; j++)
        {
            cin >> exercises_time[i][j];
        }
    }

    int total = 0;
    for (int i = 1; i <= N - 1; i++)
    {
        total += solve(i);
    }

    cout << total << endl;
}