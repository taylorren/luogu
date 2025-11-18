#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n;

char source[N][N];
char target[N][N];
char transfer[N][N];

bool isEqual()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (transfer[i][j] != target[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void output(char a[N][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}

void rotate90(char src[N][N], char dst[N][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dst[j][n - i - 1] = src[i][j];
        }
    }
}

void rotate180(char src[N][N], char dst[N][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dst[n - i - 1][n - j - 1] = src[i][j];
        }
    }
}

void rotate270(char src[N][N], char dst[N][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dst[n - j - 1][i] = src[i][j];
        }
    }
}

void reflect(char src[N][N], char dst[N][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dst[i][n - j - 1] = src[i][j];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> source[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> target[i][j];
        }
    }

    // Try Method 1: 90 degree clockwise
    rotate90(source, transfer);
    if (isEqual())
    {
        cout << "1" << endl;
        return 0;
    }

    // Try Method 2: 180 degree clockwise
    rotate180(source, transfer);
    if (isEqual())
    {
        cout << "2" << endl;
        return 0;
    }

    // Try Method 3: 270 degree clockwise
    rotate270(source, transfer);
    if (isEqual())
    {
        cout << "3" << endl;
        return 0;
    }

    // Try Method 4: Reflect
    reflect(source, transfer);
    if (isEqual())
    {
        cout << "4" << endl;
        return 0;
    }

    // Try Method 5: Reflect + rotate (90, 180, or 270)
    char temp[N][N];
    reflect(source, temp);

    // Reflect + 90
    rotate90(temp, transfer);
    if (isEqual())
    {
        cout << "5" << endl;
        return 0;
    }

    // Reflect + 180
    rotate180(temp, transfer);
    if (isEqual())
    {
        cout << "5" << endl;
        return 0;
    }

    // Reflect + 270
    rotate270(temp, transfer);
    if (isEqual())
    {
        cout << "5" << endl;
        return 0;
    }

    // Try Method 6: No change
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transfer[i][j] = source[i][j];
        }
    }
    if (isEqual())
    {
        cout << "6" << endl;
    }
    else
    {
        cout << "7" << endl;
    }
    return 0;
}