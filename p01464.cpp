#include <bits/stdc++.h>
using namespace std;

// Define a memoization table
long long memo[21][21][21];

// Recursive function with memoization
long long w(long long a, long long b, long long c)
{
    // Base cases
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }

    // Check if the result is already computed
    if (memo[a][b][c] != -1)
    {
        return memo[a][b][c];
    }

    // Compute the result and store it in the memoization table
    if (a < b && b < c)
    {
        memo[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else
    {
        memo[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

    return memo[a][b][c];
}

int main()
{
    // Initialize the memoization table with -1
    memset(memo, -1, sizeof(memo));

    long long a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }

    return 0;
}