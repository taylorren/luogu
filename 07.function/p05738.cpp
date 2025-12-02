#include <bits/stdc++.h>

#include <iomanip>
using namespace std;

int getFinalScore(vector<int> scores)
{
    int mins = 10, maxs = 0;
    int total = 0;

    for (int i = 0; i < scores.size(); i++)
    {
        if (scores[i] < mins)
        {
            mins = scores[i];
        }
        if (maxs < scores[i])
        {
            maxs = scores[i];
        }
        total += scores[i];
    }

    return total - mins - maxs;
}

int main()
{
    int n, m;
    cin >> n >> m;  // n students, each with m scores

    int max_score = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<int> scores(m, 0);
        for (int j = 0; j < m; j++)
        {
            cin >> scores[j];
        }

        max_score = max(max_score, getFinalScore(scores));
    }

    cout << fixed << setprecision(2) << (1.0 * max_score / (m - 2)) << endl;

    return 0;
}