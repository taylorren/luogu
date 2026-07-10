#include <bits/stdc++.h>
using namespace std;

int n, k, nums[20];
int prime_count = 0;

bool is_prime(int num)
{
    if (num == 2)
    {
        return true;
    }
    if (num <= 1 || num % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void dfs(int pos, int selected_count, int sum)
{
    if (selected_count == k)
    {
        if (is_prime(sum))
        {
            prime_count++;
        }
        return;
    }
    if (n - pos < k - selected_count)
    {
        return;
    }
    dfs(pos + 1, selected_count, sum);
    dfs(pos + 1, selected_count + 1, sum + nums[pos]);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    dfs(0, 0, 0);
    cout << prime_count;
}