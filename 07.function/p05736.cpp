#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    const int MAX = 101;
    int num[MAX];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (is_prime(num[i]))
        {
            cout << num[i] << " ";
        }
    }
    cout << endl;

    return 0;
}