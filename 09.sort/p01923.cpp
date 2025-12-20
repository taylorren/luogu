#include <bits/stdc++.h>
using namespace std;

void find_nth(vector<int>& nums, int l, int r, int k, int& res)
{
    if (l == r)
    {
        res = nums[l];
        return;
    }

    int left = l, right = r, guard = nums[(l + r) / 2];

    while (left <= right)
    {
        while (nums[left] < guard)
        {
            left++;
        }
        while (nums[right] > guard)
        {
            right--;
        }

        if (left <= right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    if (k <= right)
    {
        find_nth(nums, l, right, k, res);
    }
    else if (k >= left)
    {
        find_nth(nums, left, r, k, res);
    }
    else
    {
        res = guard;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, res;
    cin >> n >> k;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    find_nth(numbers, 0, n - 1, k, res);
    cout << res << endl;

    return 0;
}