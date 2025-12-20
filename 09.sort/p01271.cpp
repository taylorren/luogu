#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;  // n candidates, m votes
    cin >> n >> m;
    vector<int> votes(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        int who;
        cin >> who;
        votes[who]++;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= votes[i]; j++)
        {
            cout << i << " ";
        }
    }

    return 0;
}