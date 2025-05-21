#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int n, k;
vector<int> nums;
int count = 0;

void dfs(int pos, int selected, int sum)
{
    // 已经选择了k个数
    if (selected == k)
    {
        if (isPrime(sum))
        {
            count++;
        }
        return;
    }

    // 剩余的数不够凑齐k个
    if (n - pos < k - selected)
        return;

    // 选择当前位置的数
    if (pos < n)
    {
        dfs(pos + 1, selected + 1, sum + nums[pos]);
        // 不选择当前位置的数
        dfs(pos + 1, selected, sum);
    }
}

int main()
{
    cin >> n >> k;
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    dfs(0, 0, 0);
    cout << count << endl;

    return 0;
}