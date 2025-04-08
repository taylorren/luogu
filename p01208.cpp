#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Farmer
{
    int price;   // 牛奶单价
    int amount;  // 最大产量
};

// 按照单价升序排序
bool compare(const Farmer &a, const Farmer &b)
{
    return a.price < b.price;
}

int main()
{
    int n, m;  // n是需求量，m是奶农数量
    cin >> n >> m;

    vector<Farmer> farmers(m);
    for (int i = 0; i < m; i++)
    {
        cin >> farmers[i].price >> farmers[i].amount;
    }

    // 按单价从低到高排序
    sort(farmers.begin(), farmers.end(), compare);

    int totalCost = 0;      // 总花费
    int remainingNeed = n;  // 剩余需求量

    // 从最便宜的奶农开始购买
    for (int i = 0; i < m && remainingNeed > 0; i++)
    {
        // 计算从当前奶农处购买的数量
        int buyAmount = min(remainingNeed, farmers[i].amount);

        // 更新总花费和剩余需求量
        totalCost += buyAmount * farmers[i].price;
        remainingNeed -= buyAmount;
    }

    cout << totalCost << endl;

    return 0;
}