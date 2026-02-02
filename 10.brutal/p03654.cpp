#include <bits/stdc++.h>
using namespace std;

const char B = '#';
int countTotalEmptyCells(vector<vector<char>> court, int R, int C)
{
    int c = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (court[i][j] != B)
            {
                c++;
            }
        }
    }

    return c;
}

int countRowPlace(vector<vector<char>> court, int R, int C, int K)
{
    int c = 0;
    for (int i = 0; i < R; i++)
    {
        // Count blocked cells in first window
        int blocked = 0;
        for (int k = 0; k < K; k++)
        {
            if (court[i][k] == B)
                blocked++;
        }
        if (blocked == 0)
            c++;

        // Slide the window
        for (int j = K; j < C; j++)
        {
            // Remove leftmost cell from window
            if (court[i][j - K] == B)
                blocked--;
            // Add new rightmost cell to window
            if (court[i][j] == B)
                blocked++;

            if (blocked == 0)
                c++;
        }
    }

    return c;
}

int countColPlace(vector<vector<char>> court, int R, int C, int K)
{
    int c = 0;
    for (int j = 0; j < C; j++)
    {
        // Count blocked cells in first window
        int blocked = 0;
        for (int k = 0; k < K; k++)
        {
            if (court[k][j] == B)
                blocked++;
        }
        if (blocked == 0)
            c++;

        // Slide the window
        for (int i = K; i < R; i++)
        {
            // Remove topmost cell from window
            if (court[i - K][j] == B)
                blocked--;
            // Add new bottom cell to window
            if (court[i][j] == B)
                blocked++;

            if (blocked == 0)
                c++;
        }
    }

    return c;
}

int main()
{
    int R, C, K;
    cin >> R >> C >> K;
    vector<vector<char>> court(R, vector<char>(C));
    for (int i = 0; i < R; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < C; j++)
        {
            court[i][j] = row[j];
        }
    }

    int result = 0;

    if (K == 1)
    {
        result = countTotalEmptyCells(court, R, C);
    }
    else
    {
        result = countRowPlace(court, R, C, K) + countColPlace(court, R, C, K);
    }

    cout << result << endl;

    return 0;
}
