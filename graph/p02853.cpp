#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXK = 105;

vector<int> graph[MAXN];  // 邻接表表示有向图
bitset<MAXN> reachable
    [MAXK];  // 使用bitset优化存储，reachable[i]表示第i头牛能到达的所有牧场
int K, N, M;

// 使用BFS计算从start出发能到达的所有牧场
void bfs(int cow, int start)
{
    queue<int> q;
    vector<bool> visited(N + 1, false);

    q.push(start);
    visited[start] = true;
    reachable[cow].set(start);  // 设置对应位为1

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr])
        {
            if (!visited[next])
            {
                visited[next] = true;
                reachable[cow].set(next);  // 设置对应位为1
                q.push(next);
            }
        }
    }
}

int main()
{
    cin >> K >> N >> M;

    vector<int> cows(K + 1);
    for (int i = 1; i <= K; i++)
    {
        cin >> cows[i];  // 第i头牛所在的牧场
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);  // 添加从a到b的有向边
    }

    // 计算每头牛能到达的牧场
    for (int i = 1; i <= K; i++)
    {
        bfs(i, cows[i]);
    }

    // 统计所有牛都能到达的牧场数量
    int count = 0;
    for (int j = 1; j <= N; j++)
    {
        bool all_can_reach = true;
        for (int i = 1; i <= K; i++)
        {
            if (!reachable[i][j])
            {
                all_can_reach = false;
                break;
            }
        }
        if (all_can_reach)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}