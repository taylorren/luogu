#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {                           // 找到第一个因数 i
            cout << n / i << endl;  // 输出较大的质因数
            return 0;
        }
    }

    return 0;
}