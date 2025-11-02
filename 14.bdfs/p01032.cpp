#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <map> // 添加 map 头文件
#include <vector>

using namespace std;

// 将 rules 设为全局变量，用于存储变换规则
map<string, string> rules;

// 函数用于计算从字符串 A 到字符串 B 的最少变换步数
int minTransformations(const string& A, const string& B)
{
    // 如果 A 和 B 相同，则无需变换
    if (A == B)
    {
        return 0;
    }

    // 使用 unordered_map 存储每个字符串状态及其对应的步数
    unordered_map<string, int> steps_reaching;
    // 使用队列进行广度优先搜索
    queue<pair<string, int>> q;
    // 初始化队列和步数映射
    q.push({A, 0});
    steps_reaching[A] = 0;

    // 开始广度优先搜索
    while (!q.empty())
    {
        // 取出队列中的当前字符串状态和步数
        auto [current, steps] = q.front();
        q.pop();

        // 如果步数达到或超过 10，则停止继续搜索
        if (steps >= 10)
        {
            continue;
        }

        // 遍历所有变换规则
        for (const auto& rule : rules)
        {
            const string& from = rule.first; // 变换的源字符串
            const string& to = rule.second;  // 变换的目标字符串

            // 查找当前字符串中是否存在源字符串
            size_t pos = current.find(from);
            while (pos != string::npos)
            {
                // 生成新的字符串状态
                string next = current;
                next.replace(pos, from.length(), to);

                // 如果新状态等于目标字符串 B，则返回步数
                if (next == B)
                {
                    return steps + 1;
                }

                // 如果新状态未被访问过或当前路径更短，则更新步数并加入队列
                if (steps_reaching.find(next) == steps_reaching.end() || steps_reaching[next] > steps + 1)
                {
                    steps_reaching[next] = steps + 1; // 更新步数
                    q.push({next, steps + 1});
                }

                // 查找下一个可能的源字符串位置
                pos = current.find(from, pos + 1);
            }
        }
    }

    // 如果在 10 步内无法达到目标字符串，则返回 -1
    return -1;
}

int main()
{
    string A, B;
    // 读取初始字符串 A 和目标字符串 B
    cin >> A >> B;

    string from, to;
    // 读取变换规则并存储到全局 map 中
    while (cin >> from >> to)
    {
        rules[from] = to;
    }

    // 计算最少变换步数
    int result = minTransformations(A, B);
    // 输出结果
    if (result != -1)
    {
        cout << result << endl;
    }
    else
    {
        cout << "NO ANSWER!" << endl;
    }

    return 0;
}