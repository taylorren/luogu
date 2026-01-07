#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << "Jolly" << endl;
        return 0;
    }

    vector<bool> diff(n, false);

    int current, prev;
    cin >> prev;
    bool jolly = true;

    for (int i = 1; i < n; i++)
    {
        cin >> current;
        int d = abs(current - prev);
        if (d > 0 && d <= n - 1)  // the diff is valid
        {
            diff[d] = true;
        }

        prev = current;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        if (!diff[i])
        {
            jolly = false;
            break;
        }
    }

    if (jolly)
    {
        cout << "Jolly";
    }
    else
    {
        cout << "Not jolly";
    }

    return 0;
}