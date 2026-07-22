#include <bits/stdc++.h>
using namespace std;

const int BLOCK_SIZE = 2;  // N*N 的宫
const int N = BLOCK_SIZE * BLOCK_SIZE;           // N*N 数独

int grid[N * N + 1];       // 棋盘，1-indexed
int ans = 0;

// 占用标记：rowUsed[r][num] = 1 表示第 r 行已经用了 num
int rowUsed[N + 1][N + 1];
int colUsed[N + 1][N + 1];
int blkUsed[N + 1][N + 1];

// 根据行列计算宫编号 (1-based)
int getBlock(int row, int col)
{
    return (row - 1) / BLOCK_SIZE * BLOCK_SIZE + (col - 1) / BLOCK_SIZE + 1;
}

// 判断能否在 (row, col) 放置数字 num
bool isPlaceable(int row, int col, int num)
{
    int b = getBlock(row, col);
    return rowUsed[row][num] == 0 && colUsed[col][num] == 0 &&
           blkUsed[b][num] == 0;
}

// 放置数字 num 到 (row, col)
void place(int row, int col, int num)
{
    int b = getBlock(row, col);
    rowUsed[row][num] = 1;
    colUsed[col][num] = 1;
    blkUsed[b][num] = 1;
}

// 撤销放置在 (row, col) 的数字 num
void remove(int row, int col, int num)
{
    int b = getBlock(row, col);
    rowUsed[row][num] = 0;
    colUsed[col][num] = 0;
    blkUsed[b][num] = 0;
}

void printBoard()
{
    for (int i = 1; i <= N * N; i++)
    {
        cout << grid[i] << " ";
        if (i % N == 0)
            cout << endl;
    }
    cout << "=============" << endl;
}

void dfs(int x)
{
    if (x > N * N)
    {  // 所有格子填完 → 找到一个解
        ans++;
        printBoard();
        return;
    }

    int row = (x - 1) / N + 1;
    int col = (x - 1) % N + 1;

    for (int num = 1; num <= N; num++)
    {
        if (isPlaceable(row, col, num))
        {
            grid[x] = num;
            place(row, col, num);   // 标记占用
            dfs(x + 1);             // 递归下一格
            remove(row, col, num);  // 回溯：撤销占用
        }
    }
}

int main()
{
    dfs(1);
    cout << "Total solutions: " << ans << endl;
    return 0;
}
