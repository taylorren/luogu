#include <bits/stdc++.h>
using namespace std;

struct Vertex
{
    bool exists = false;  // 标记字母是否出现
    int in = 0;           // 入度
    int out = 0;          // 出度
};

struct Edge
{
    int to;       // 目标节点
    int ord;      // 单词序号
    string word;  // 单词本身
};

// 并查集查找函数
int find(vector<int>& fa, int x)
{
    if (fa[x] != x)
        return fa[x] = find(fa, fa[x]);
    return fa[x];
}

// 并查集合并函数
void unionSets(vector<int>& fa, int x, int y)
{
    fa[y] = x;
}

// 计算并查集中的集合数量
int countSets(const vector<Vertex>& vertices, const vector<int>& fa)
{
    int count = 0;
    for (int i = 1; i <= 26; i++)
    {
        if (vertices[i].exists && fa[i] == i)
        {
            count++;
        }
    }
    return count;
}

// 检查欧拉路径是否存在，如果不存在则返回错误原因
string checkEulerPath(const vector<Vertex>& vertices, int& eulerStart,
                      int& eulerEnd)
{
    // 检查每个节点的入度和出度
    for (int i = 1; i <= 26; i++)
    {
        if (!vertices[i].exists)
        {
            continue;
        }

        if (vertices[i].out == vertices[i].in + 1)
        {
            // 可能的起点
            if (eulerStart)
            {
                return "存在多个起点，无法形成欧拉路径";
            }
            eulerStart = i;
        }
        else if (vertices[i].in == vertices[i].out + 1)
        {
            // 可能的终点
            if (eulerEnd)
            {
                return "存在多个终点，无法形成欧拉路径";
            }
            eulerEnd = i;
        }
        else if (vertices[i].in == vertices[i].out)
        {
            // 正常节点，入度等于出度
            continue;
        }
        else
        {
            return "存在节点的入度和出度差值大于1，无法形成欧拉路径";
        }
    }

    // 检查起点和终点是否成对出现
    if ((eulerStart && !eulerEnd) || (!eulerStart && eulerEnd))
    {
        return "起点和终点必须同时存在或同时不存在";
    }

    // 通过所有检查，欧拉路径存在
    return "";
}

// DFS寻找欧拉路径
void dfs(int step, int current, int prevEdge, int n,
         const vector<vector<Edge>>& graph, vector<int>& visited,
         vector<string>& result, vector<string>& words)
{
    if (step == n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << result[i];
            if (i < n)
                cout << ".";
        }
        exit(0);
    }

    for (size_t k = 0; k < graph[current].size(); k++)
    {
        const Edge& edge = graph[current][k];
        if (!visited[edge.ord])
        {
            visited[edge.ord] = 1;
            result[step + 1] = edge.word;
            dfs(step + 1, edge.to, edge.ord, n, graph, visited, result, words);
        }
    }

    visited[prevEdge] = 0;  // 回溯
}

int main()
{
    int n;
    cin >> n;

    vector<string> words(n + 1);
    vector<string> result(n + 1);
    vector<int> visited(n + 1, 0);
    vector<Vertex> vertices(27);
    vector<int> fa(27);
    vector<vector<Edge>> graph(27);

    // 初始化并查集
    for (int i = 1; i <= 26; i++)
    {
        fa[i] = i;
    }

    // 读入单词
    for (int i = 1; i <= n; i++)
    {
        cin >> words[i];
    }

    // 按字典序排序
    sort(words.begin() + 1, words.end(),
         [](const string& a, const string& b) { return a < b; });

    // 构建图
    for (int i = 1; i <= n; i++)
    {
        int startChar = words[i][0] - 'a' + 1;
        int endChar = words[i][words[i].length() - 1] - 'a' + 1;

        // 更新入度和出度
        vertices[startChar].out++;
        vertices[endChar].in++;

        // 标记节点存在
        if (!vertices[startChar].exists)
        {
            vertices[startChar].exists = true;
        }

        if (!vertices[endChar].exists)
        {
            vertices[endChar].exists = true;
        }

        // 合并连通分量
        if (startChar != endChar)
        {
            int rootStart = find(fa, startChar);
            int rootEnd = find(fa, endChar);
            if (rootStart != rootEnd)
            {
                unionSets(fa, rootStart, rootEnd);
            }
        }

        // 添加边
        Edge edge;
        edge.to = endChar;
        edge.ord = i;
        edge.word = words[i];
        graph[startChar].push_back(edge);
    }

    // 检查图是否连通
    if (countSets(vertices, fa) != 1)
    {
        cout << "***" << endl;
        return 0;
    }

    // 检查欧拉路径
    int eulerStart = 0, eulerEnd = 0;
    string error = checkEulerPath(vertices, eulerStart, eulerEnd);
    if (!error.empty())
    {
        cout << "***" << endl;
        // 如果需要输出错误原因，可以取消下面的注释
        // cout << "错误原因: " << error << endl;
        return 0;
    }

    // 如果没有明确的起点，选择第一个单词的首字母作为起点
    if (!eulerStart)
    {
        eulerStart = words[1][0] - 'a' + 1;
    }

    // 使用DFS寻找欧拉路径
    dfs(0, eulerStart, 0, n, graph, visited, result, words);

    return 0;
}
