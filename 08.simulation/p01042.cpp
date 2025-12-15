#include <bits/stdc++.h>
using namespace std;

void print_result(vector<int> win_lose, int n)
{
    int win = 0, lose = 0;
    for (int i = 0; i < win_lose.size(); i++)
    {
        if (win_lose[i] == 1)
        {
            win++;
        }
        else
        {
            lose++;
        }
        if (max(win, lose) >= n && abs(win - lose) >= 2)
        {
            cout << win << ":" << lose << endl;
            win = 0;
            lose = 0;
        }
    }
    cout << win << ":" << lose << endl;
}

int main()
{
    vector<int> win_lose;
    char s;
    bool more_input = true;
    while (more_input)
    {
        cin >> s;
        if (s == 'E')  // Game over
        {
            more_input = false;
        }
        else if (s == 'W')
        {
            win_lose.push_back(1);
        }
        else if (s == 'L')
        {
            win_lose.push_back(0);
        }
    }

    print_result(win_lose, 11);
    cout << endl;
    print_result(win_lose, 21);

    return 0;
}