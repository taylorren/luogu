#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, NA, NB;
    cin >> N >> NA >> NB;

    // 读取小A的出拳周期
    vector<int> A(NA);
    for (int i = 0; i < NA; i++)
    {
        cin >> A[i];
    }

    // 读取小B的出拳周期
    vector<int> B(NB);
    for (int i = 0; i < NB; i++)
    {
        cin >> B[i];
    }

    // 定义胜负关系表
    // 0-剪刀，1-石头，2-布，3-蜥蜴人，4-斯波克
    // win[a][b] = 1表示a赢b，-1表示a输b，0表示平局
    int win[5][5] = {
        {0, -1, 1, 1, -1},  // 剪刀vs其他
        {1, 0, -1, 1, -1},  // 石头vs其他
        {-1, 1, 0, -1, 1},  // 布vs其他
        {-1, -1, 1, 0, 1},  // 蜥蜴人vs其他
        {1, 1, -1, -1, 0}   // 斯波克vs其他
    };

    int scoreA = 0, scoreB = 0;

    // 模拟N次猜拳
    for (int i = 0; i < N; i++)
    {
        int gestureA = A[i % NA];  // 小A的出拳
        int gestureB = B[i % NB];  // 小B的出拳

        if (win[gestureA][gestureB] == 1)
        {
            scoreA++;  // 小A赢
        }
        else if (win[gestureA][gestureB] == -1)
        {
            scoreB++;  // 小B赢
        }
        // 平局不加分
    }

    cout << scoreA << " " << scoreB << endl;

    return 0;
}