#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Ship
{
    int time;                // 船到达的时间
    vector<int> passengers;  // 船上乘客的国籍
};

int main()
{
    int n;
    cin >> n;

    vector<Ship> ships;

    // 读取所有船的信息
    for (int i = 0; i < n; i++)
    {
        int t, k;
        cin >> t >> k;

        vector<int> passengers(k);
        for (int j = 0; j < k; j++)
        {
            cin >> passengers[j];
        }

        ships.push_back({t, passengers});
    }

    // 使用队列维护24小时内的船只
    queue<Ship> window;
    // 使用哈希表统计24小时内各国家的乘客数量
    unordered_map<int, int> country_count;

    for (int i = 0; i < n; i++)
    {
        Ship current = ships[i];

        // 将当前船加入窗口
        window.push(current);

        // 更新国家统计
        for (int nationality : current.passengers)
        {
            country_count[nationality]++;
        }

        // 移除24小时前的船只
        while (!window.empty() && window.front().time <= current.time - 86400)
        {
            Ship old_ship = window.front();
            window.pop();

            // 更新国家统计
            for (int nationality : old_ship.passengers)
            {
                country_count[nationality]--;
                if (country_count[nationality] == 0)
                {
                    country_count.erase(nationality);
                }
            }
        }

        // 输出当前24小时内不同国家的数量
        cout << country_count.size() << endl;
    }

    return 0;
}