#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int w0, w, m;
    cin >> w0 >> w >> m;

    double left = 0.0;
    double right = 3.0;
    double mid;

    while (right - left > 1e-8)
    {
        mid = (left + right) / 2;
        double t = w0;
        for (int i = 1; i <= m; i++)
        {
            t = t * (1 + mid) - w;  // 不需要除以100，因为最后才转换为百分比
        }
        
        if (fabs(t) < 1e-8) {  // 处理接近0的情况
            break;
        }
        else if (t > 0)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    
    cout << fixed << setprecision(1) << mid * 100 << endl;  // 最后转换为百分比

    return 0;
}