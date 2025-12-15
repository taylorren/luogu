#include <bits/stdc++.h>
using namespace std;

const int N = 10;
char maps[N][N];

int steps[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool legal_move(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N || maps[x][y] == '*')
    {
        return false;
    }
    else
    {
        return true;
    }
}
struct Entity
{
    int x, y;       // Tracks the position
    int direction;  // Tracks the diretion to move
    void move()
    {
        int next_x = x + steps[direction][0];
        int next_y = y + steps[direction][1];

        if (legal_move(next_x, next_y))
        {
            x = next_x;
            y = next_y;
        }
        else
        {
            direction = (direction + 1) % 4;
        }
    }
};

int main()
{
    Entity cow, farmer;
    cow.direction = 0;
    farmer.direction = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c;
            cin >> c;
            if (c == 'F')  // Farmer here
            {
                farmer.x = i;
                farmer.y = j;
                c = '.';
            }
            else if (c == 'C')  // Cow here
            {
                cow.x = i;
                cow.y = j;
                c = '.';
            }

            maps[i][j] = c;
        }
    }

    // Above initialize the map and make it only contains '*' or '.'. Farmer/Cow
    // location is recorded for further processing

    int ans = 0;
    int max_loop = 15000;

    while (ans <= max_loop)  // Let's try
    {
        ans++;
        cow.move();
        farmer.move();

        if (cow.x == farmer.x && cow.y == farmer.y)
        {
            cout << ans << endl;
            return 0;
        }
    }

    cout << 0 << endl;
}