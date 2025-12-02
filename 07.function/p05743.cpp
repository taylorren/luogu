#include <iostream>
using namespace std;

// 顺推方式：递归计算第 day 天开始时有多少个桃子
int calculatePeaches(int day, int n)
{
    if (day == n)
    {
        return 1;  // 第 n 天早上剩 1 个
    }
    
    // 第 day+1 天开始时的桃子数
    int nextDay = calculatePeaches(day + 1, n);
    
    // 第 day 天开始时的桃子数 = (第 day+1 天的数量 + 1) × 2
    return (nextDay + 1) * 2;
}

int main()
{
    int n;
    cin >> n;
    
    int peaches = 1;  // 第 n 天早上剩 1 个
    
    // 从第 n 天逆推到第 1 天
    for (int i = 1; i < n; i++)
    {
        peaches = (peaches + 1) * 2;
    }
    
    cout << peaches << endl;
    
    // 也可以用顺推递归方式
    // cout << calculatePeaches(1, n) << endl;
    
    return 0;
}
