#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 20005;
const int MAXM = 100005;

struct Edge
{
    int x, y, z;
};

bool cmp(const Edge& a, const Edge& b)
{
    return a.z > b.z;
}

int parent[MAXN];
int enemy[MAXN];
Edge edges[MAXM];

int find(int x)
{
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        parent[x] = y;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].x >> edges[i].y >> edges[i].z;
    }

    sort(edges, edges + m, cmp);

    for (int i = 0; i <= m; ++i)
    {
        if (i == m)
        {
            cout << "0" << endl;
            break;
        }

        int x = find(edges[i].x);
        int y = find(edges[i].y);

        if (x == y)
        {
            cout << edges[i].z << endl;
            break;
        }
        else
        {
            if (!enemy[edges[i].x])
            {
                enemy[edges[i].x] = edges[i].y;
            }
            else
            {
                unite(enemy[edges[i].x], edges[i].y);
            }

            if (!enemy[edges[i].y])
            {
                enemy[edges[i].y] = edges[i].x;
            }
            else
            {
                unite(enemy[edges[i].y], edges[i].x);
            }
        }
    }

    return 0;
}