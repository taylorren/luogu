#include <bits/stdc++.h>
using namespace std;

long long catalan(int n) {
    if (n <= 1) return 1;
    
    // Calculate C(n) = (2n)! / ((n+1)! * n!) = (2n choose n) / (n+1)
    // Using the formula: C(n) = (2n * (2n-1) * ... * (n+2)) / (n!)
    long long result = 1;
    for (int i = 0; i < n; ++i) {
        result = result * (2 * n - i) / (i + 1);
    }
    return result / (n + 1);
}

int main()
{
    int n;
    cin >> n;
    
    cout << catalan(n) << endl;
    return 0;
}