#include <bits/stdc++.h>
using namespace std;

struct Direction
{
    int x;
    int y;
};

Direction dir[8] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                    {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

const int MAX = 105;
char board[MAX][MAX];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (board[i][j] != '*')
            {
                int count = 0;
                for (int k = 0; k < 8; k++)
                {
                    int x = i + dir[k].x;
                    int y = j + dir[k].y;
                    if (board[x][y] == '*')
                    {
                        count++;
                    }
                }
                cout << count;
            }
            else
            {
                cout << '*';
            }
        }
        cout << endl;
    }

    return 0;
}
