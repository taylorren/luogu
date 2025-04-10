#include <cmath>
#include <iostream>
using namespace std;

// 递归函数，用于填补地毯
// (x1, y1)是特殊点（公主所在位置）的坐标
// (x2, y2)是当前处理的子棋盘左上角的坐标
// n是当前子棋盘的大小
void solve(int x1, int y1, int x2, int y2, int n)
{
    if (n == 1)
        return;
    if (x1 - x2 < (n >> 1))
    {
        if (y1 - y2 < (n >> 1))
        {
            // 特殊点在左上子棋盘，放置形状1的地毯（拐点在右下角）
            cout << (x2 + (n >> 1)) << ' ' << (y2 + (n >> 1)) << ' ' << 1
                      << endl;
            solve(x1, y1, x2, y2, (n >> 1));
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1), x2, y2 + (n >> 1),
                  (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1) - 1, x2 + (n >> 1), y2,
                  (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1), x2 + (n >> 1), y2 + (n >> 1),
                  (n >> 1));
        }
        else
        {
            // 特殊点在右上子棋盘，放置形状2的地毯（拐点在左下角）
            cout << (x2 + (n >> 1)) << ' ' << (y2 + (n >> 1) - 1) << ' '
                      << 2 << endl;
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1) - 1, x2, y2, (n >> 1));
            solve(x1, y1, x2, y2 + (n >> 1), (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1) - 1, x2 + (n >> 1), y2,
                  (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1), x2 + (n >> 1), y2 + (n >> 1),
                  (n >> 1));
        }
    }
    else
    {
        if (y1 - y2 < (n >> 1))
        {
            // 特殊点在左下子棋盘，放置形状3的地毯（拐点在右上角）
            cout << (x2 + (n >> 1) - 1) << ' ' << (y2 + (n >> 1)) << ' '
                      << 3 << endl;
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1) - 1, x2, y2, (n >> 1));
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1), x2, y2 + (n >> 1),
                  (n >> 1));
            solve(x1, y1, x2 + (n >> 1), y2, (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1), x2 + (n >> 1), y2 + (n >> 1),
                  (n >> 1));
        }
        else
        {
            // 特殊点在右下子棋盘，放置形状4的地毯（拐点在左上角）
            cout << (x2 + (n >> 1) - 1) << ' ' << (y2 + (n >> 1) - 1)
                      << ' ' << 4 << endl;
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1) - 1, x2, y2, (n >> 1));
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1), x2, y2 + (n >> 1),
                  (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1) - 1, x2 + (n >> 1), y2,
                  (n >> 1));
            solve(x1, y1, x2 + (n >> 1), y2 + (n >> 1), (n >> 1));
        }
    }
}

int main()
{
    int k, x, y;
    cin >> k >> x >> y;

    // 计算棋盘大小
    int size = 1 << k;  // 2^k

    // 调用递归函数填补地毯
    solve(x, y, 1, 1, size);

    return 0;
}