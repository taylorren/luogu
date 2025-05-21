#include <iostream>
#include <vector>
using namespace std;

// 每个数字需要的火柴棍数量
const int matchsticks[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

// 计算一个数字需要的火柴棍数量
int countMatchsticks(int num)
{
    if (num == 0)
        return matchsticks[0];

    int count = 0;
    while (num > 0)
    {
        count += matchsticks[num % 10];
        num /= 10;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    // 减去加号和等号所需的4根火柴棍
    int remainingMatchsticks = n - 4;

    // 如果剩余的火柴棍不足以拼出任何数字，则无解
    if (remainingMatchsticks < 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int count = 0;

    // 枚举所有可能的A和B
    // 由于数字可能很大，我们设置一个合理的上限
    // 考虑到最少的火柴棍数是1需要2根，所以最大可能的数字不会超过remainingMatchsticks/2
    int upperLimit = 1000;  // 设置一个合理的上限

    for (int a = 0; a <= upperLimit; a++)
    {
        int matchsticksA = countMatchsticks(a);
        if (matchsticksA > remainingMatchsticks)
            continue;

        for (int b = 0; b <= upperLimit; b++)
        {
            int matchsticksB = countMatchsticks(b);
            if (matchsticksA + matchsticksB > remainingMatchsticks)
                continue;

            int c = a + b;
            int matchsticksC = countMatchsticks(c);

            // 检查火柴棍总数是否正好等于n
            if (matchsticksA + matchsticksB + matchsticksC + 4 == n)
            {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}