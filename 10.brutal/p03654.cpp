#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int R, C, K;
    cin >> R >> C >> K;

    // 读取篮球场布局
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

    int total_ways = 0;

    // 特殊处理 K=1 的情况
    if (K == 1)
    {
        // 只需计算所有空地的数量
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (court[i][j] == '.')
                {
                    total_ways++;
                }
            }
        }
    }
    else
    {
        // 检查每一行中可能的站位方式
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j <= C - K; j++)
            {
                bool valid = true;
                for (int k = 0; k < K; k++)
                {
                    if (court[i][j + k] == '#')
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    total_ways++;
                }
            }
        }

        // 检查每一列中可能的站位方式
        for (int j = 0; j < C; j++)
        {
            for (int i = 0; i <= R - K; i++)
            {
                bool valid = true;
                for (int k = 0; k < K; k++)
                {
                    if (court[i + k][j] == '#')
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    total_ways++;
                }
            }
        }
    }

    cout << total_ways << endl;
    return 0;
}