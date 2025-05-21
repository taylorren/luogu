#include <bits/stdc++.h>
using namespace std;

const int N = 10;
char grid[N][N + 1];  // +1用于存储字符串结束符

// 方向：北、东、南、西（顺时针顺序）
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

struct Entity
{
    int x, y;     // 位置
    int dir = 0;  // 方向，初始为北（0）

    void move()
    {
        // 检查前方是否有障碍
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N || grid[nx][ny] == '*')
        {
            // 有障碍，顺时针旋转90度
            dir = (dir + 1) % 4;
        }
        else
        {
            // 无障碍，前进一步
            x = nx;
            y = ny;
        }
    }
};

int main()
{
    // 读入地图
    Entity cow, john;
    for (int i = 0; i < N; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 'C')
            {
                cow.x = i;
                cow.y = j;
                grid[i][j] = '.';  // 将牛的位置标记为空地，便于后续移动
            }
            else if (grid[i][j] == 'F')
            {
                john.x = i;
                john.y = j;
                grid[i][j] = '.';  // 将John的位置标记为空地，便于后续移动
            }
        }
    }

    // 模拟移动
    int time = 0;
    const int MAX_TIME = 160000;  // 最大时间限制，防止无限循环

    while (time < MAX_TIME)
    {
        time++;

        // 牛和John同时移动
        cow.move();
        john.move();

        // 检查是否相遇
        if (cow.x == john.x && cow.y == john.y)
        {
            cout << time << endl;
            return 0;
        }
    }

    // 如果超过最大时间限制仍未相遇，认为永远不会相遇
    cout << 0 << endl;
    return 0;
}