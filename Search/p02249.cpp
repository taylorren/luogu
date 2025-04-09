#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<int> queries(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> queries[i];
    }

    vector<int> results;
    for (int q : queries)
    {
        // 使用 lower_bound 查找第一次出现的位置
        auto it = lower_bound(a.begin(), a.end(), q);
        if (it != a.end() && *it == q)
        {
            results.push_back(it - a.begin() + 1);  // 转换为 1-based 索引
        }
        else
        {
            results.push_back(-1);
        }
    }

    // 输出结果
    for (int i = 0; i < results.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << results[i];
    }
    cout << endl;

    return 0;
}