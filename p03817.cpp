#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<long long> a(n);  // 使用long long存储糖果数量
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long eat = 0;  // 需要吃掉的糖果总数

    // 从左到右遍历
    for (int i = 0; i < n - 1; i++)
    {
        // 如果当前两个糖果盒的糖果和超过x
        if (a[i] + a[i + 1] > x)
        {
            // 需要吃掉的糖果数量
            long long need_to_eat = a[i] + a[i + 1] - x;

            // 从右边盒子中吃掉糖果
            long long eat_from_next = min(need_to_eat, a[i + 1]);
            a[i + 1] -= eat_from_next;
            eat += eat_from_next;

            // 如果还需要吃掉更多糖果，从当前盒子中吃
            if (a[i] + a[i + 1] > x)
            {
                long long remaining = a[i] + a[i + 1] - x;
                a[i] -= remaining;
                eat += remaining;
            }
        }
    }

    cout << eat << endl;

    return 0;
}