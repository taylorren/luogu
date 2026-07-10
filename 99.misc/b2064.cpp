#include <bits/stdc++.h>
using namespace std;

long long fib(int n)
{
    if(n <= 1)
        return n;
    long long a = 0, b = 1, c;
    for(int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        int x;
        cin >> x;
        cout << fib(x) << endl;
    }
    return 0;
}