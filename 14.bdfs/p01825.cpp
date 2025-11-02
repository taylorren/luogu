#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// 定义点结构，包含坐标和到达该点的时间
struct Point
{
    int x, y, time;
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> maze(N);                           // 存储迷宫地图
    unordered_map<char, vector<pair<int, int>>> slides; // 存储每个滑梯字母对应的所有端点位置
    Point start, exit;                                // 起点和出口位置

    // 读取迷宫并记录起点、出口和滑梯端点
    for (int i = 0; i < N; ++i)
    {
        cin >> maze[i];
        for (int j = 0; j < M; ++j)
        {
            if (maze[i][j] == '@')
            {
                start = {i, j, 0};                    // 记录起点位置，初始时间为0
                maze[i][j] = '.';                     // 将起点标记为普通草地，避免后续处理时的干扰
            }
            else if (maze[i][j] == '=')
            {
                exit = {i, j, 0};                     // 记录出口位置
            }
            else if (isupper(maze[i][j]))             // 识别大写字母（滑梯端点）
            {
                slides[maze[i][j]].push_back({i, j}); // 将端点添加到对应字母的列表中
            }
        }
    }

    // 使用BFS搜索最短路径
    queue<Point> q;
    q.push(start);                                    // 将起点加入队列
    vector<vector<int>> dist(N, vector<int>(M, -1));  // 记录到达每个位置的最短时间，-1表示未访问
    dist[start.x][start.y] = 0;                       // 起点的时间为0

    // 四个方向的移动：下、上、右、左
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty())
    {
        Point current = q.front();                    // 获取当前处理的位置
        q.pop();

        // 如果到达出口，输出时间并结束
        if (current.x == exit.x && current.y == exit.y)
        {
            cout << current.time << endl;
            return 0;
        }

        // 尝试向四个方向移动
        for (auto& dir : directions)
        {
            int nx = current.x + dir[0];              // 计算新位置的坐标
            int ny = current.y + dir[1];

            // 检查新位置是否有效（在地图范围内且不是墙）
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#')
            {
                int new_time = current.time + 1;      // 移动到新位置需要1单位时间
                
                // 如果新位置是滑梯端点，立即传送到另一端
                if (isupper(maze[nx][ny]))
                {
                    char slideChar = maze[nx][ny];    // 获取滑梯字母
                    for (auto& endpoint : slides[slideChar]) // 遍历该滑梯的所有端点
                    {
                        // 找到不是当前端点的另一个端点
                        if (endpoint.first != nx || endpoint.second != ny)
                        {
                            // 如果另一端点未访问过或找到更短路径，则更新
                            if (dist[endpoint.first][endpoint.second] == -1 || 
                                dist[endpoint.first][endpoint.second] > new_time)
                            {
                                dist[endpoint.first][endpoint.second] = new_time;
                                q.push({endpoint.first, endpoint.second, new_time});
                            }
                            break; // 只传送到另一端，不需要继续遍历
                        }
                    }
                }
                // 如果新位置是普通草地或出口
                else if (dist[nx][ny] == -1 || dist[nx][ny] > new_time)
                {
                    dist[nx][ny] = new_time;          // 更新到达该位置的最短时间
                    q.push({nx, ny, new_time});       // 将新位置加入队列
                }
            }
        }
    }

    // 如果无法到达出口，输出提示信息
    cout << "NO ANSWER!" << endl;
    return 0;
}