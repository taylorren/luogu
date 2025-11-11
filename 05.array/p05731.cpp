#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int x[9][9] = {0};
    
    // 方向数组：右、下、左、上（顺时针）
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    int curr_x = 0, curr_y = 0;
    int curr_dir = 0;  // 0=右, 1=下, 2=左, 3=上

    for (int i = 1; i <= n * n; i++)
    {
        x[curr_x][curr_y] = i;
        
        // 尝试按当前方向前进
        int next_x = curr_x + dx[curr_dir];
        int next_y = curr_y + dy[curr_dir];
        
        // 如果越界或已填数字，则转向
        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || x[next_x][next_y] != 0)
        {
            curr_dir = (curr_dir + 1) % 4;  // 顺时针转向
            next_x = curr_x + dx[curr_dir];
            next_y = curr_y + dy[curr_dir];
        }
        
        curr_x = next_x;
        curr_y = next_y;
    }

    // 输出矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(3)<<x[i][j];
        }
        cout << "\n";
    }

    return 0;
}