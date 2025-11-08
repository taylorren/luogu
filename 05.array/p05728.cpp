#include <bits/stdc++.h>
using namespace std;

struct Score
{
    int chinese, math, english;
};

int main()
{
    int n;
    cin >> n;

    vector<Score> scores(n);

    for (int i = 0; i < n; i++)
    {
        cin >> scores[i].chinese >> scores[i].math >> scores[i].english;
    }

    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // 总分差不超过10，且各科差都不超过5
            int total_i =
                scores[i].chinese + scores[i].math + scores[i].english;
            int total_j =
                scores[j].chinese + scores[j].math + scores[j].english;
            if (abs(total_i - total_j) <= 10 &&
                abs(scores[i].chinese - scores[j].chinese) <= 5 &&
                abs(scores[i].math - scores[j].math) <= 5 &&
                abs(scores[i].english - scores[j].english) <= 5)
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}