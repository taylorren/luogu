#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[30];
    memset(a, 0, sizeof(a));

    int n, r;
    cin >> n >> r;

    int total = (1 << n);
    for (int S = total - 1; S >= 0; S--)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (S & (1 << i))  // Masked
            {
                a[count] = i;
                count++;
            }
        }

        if (count == r)  // exactly r numbers
        {
            for (int i = r - 1; i >= 0; i--)
            {
                cout << setw(3) << n - a[i];
            }
            cout << endl;
        }
    }

    return 0;
}