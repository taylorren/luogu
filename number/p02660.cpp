#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to calculate minimum perimeter sum
ll min_perimeter(ll x, ll y)
{
    if (x == 0 || y == 0)
        return 0;  // Base case: no area left

    // Always make x the smaller dimension
    if (x > y)
        swap(x, y);

    // Number of squares with side length x
    ll num_squares = y / x;

    // Perimeter of all squares with side length x
    ll perimeter = 4 * x * num_squares;

    // Recursively calculate for remaining area
    ll remaining = min_perimeter(x, y % x);

    return perimeter + remaining;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, y;
    cin >> x >> y;

    cout << min_perimeter(x, y) << endl;

    return 0;
}