#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

// 定义三次方程 f(x) = ax^3 + bx^2 + cx + d
double f(double x, double a, double b, double c, double d)
{
    return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    // 定义根的范围 [-100, 100]
    double roots[3];  // 用于存储三个实根
    int root_count = 0;

    // 遍历区间 [-100, 100]，每次检查跨度为 1 的小区间
    for (double left = -100; left < 100 && root_count < 3; left += 1)
    {
        double right = left + 1;

        // 确保当前小区间内有一个根
        if (f(left, a, b, c, d) * f(right, a, b, c, d) > 0)
        {
            continue;  // 如果没有根，跳过该区间
        }

        // 在当前小区间内使用二分法找到一个根
        double mid;
        while (right - left > 1e-6)
        {  // 精度控制到 1e-6
            mid = (left + right) / 2;
            if (f(left, a, b, c, d) * f(mid, a, b, c, d) <= 0)
            {
                right = mid;  // 根在 [left, mid]
            }
            else
            {
                left = mid;  // 根在 [mid, right]
            }
        }

        // 找到一个根，存储并继续查找下一个根
        roots[root_count++] = (left + right) / 2;
    }

    // 输出三个根，精确到小数点后两位
    cout << fixed << setprecision(2) << roots[0] << " " << roots[1] << " " << roots[2] << endl;

    return 0;
}