#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> compressed;
    int num;

    // 读取压缩码（除了第一个数字n之外的所有数字）
    while (cin >> num)
    {
        compressed.push_back(num);
    }

    // 创建一个一维数组来存储展开后的点阵
    vector<int> decompressed;

    // 解压缩
    bool is_zero = true;  // 从0开始交替
    for (int count : compressed)
    {
        // 添加count个is_zero值到decompressed
        for (int i = 0; i < count; i++)
        {
            decompressed.push_back(is_zero ? 0 : 1);
        }
        // 切换is_zero的值
        is_zero = !is_zero;
    }

    // 输出点阵
    for (int i = 0; i < n * n; i++)
    {
        cout << decompressed[i];
        // 每行结束后换行
        if ((i + 1) % n == 0)
        {
            cout << endl;
        }
    }

    return 0;
}