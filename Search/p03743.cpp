#include <iomanip>
#include <iostream>
using namespace std;

const int MAXN = 200000;
int n;
double p;

struct Device
{
    double consume, energy;
} devices[MAXN];

bool check(double time)
{
    double charge_capacity = p * time;  // 预先计算充电容量
    double need = 0;

    for (int i = 0; i < n; i++)
    {
        double consume = devices[i].consume * time;
        if (consume > devices[i].energy)
        {
            need += (consume - devices[i].energy);
            if (need > charge_capacity)
                return false;  // 提前返回
        }
    }

    return true;
}

int main()
{
    cin >> n >> p;

    double total_consume = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> devices[i].consume >> devices[i].energy;
        total_consume += devices[i].consume;
    }

    if (total_consume <= p)
    {
        cout << -1.000000 << endl;
        return 0;
    }

    double left = 0, right = 1e10;
    while (right - left > 1e-6)
    {
        double mid = (left + right) / 2;
        if (check(mid))
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    cout << fixed << setprecision(6) << left << endl;

    return 0;
}