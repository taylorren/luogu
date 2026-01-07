#include <bits/stdc++.h>
using namespace std;

long long doReverse(vector<int>& trains, vector<int>& tmp, int left, int right)
{
    if (left >= right)
    {
        return 0;
    }

    int mid = (left + right) / 2;
    long long counts = doReverse(trains, tmp, left, mid) +
                       doReverse(trains, tmp, mid + 1, right);

    int i = left, j = mid + 1, k = left;  // 三个指针
    while (i <= mid && j <= right)
    {
        if (trains[i] <= trains[j])  // 不是逆序
        {
            tmp[k++] = trains[i++];
        }
        else  // 出现逆序对，所以需要调整一次
        {
            tmp[k++] = trains[j++];
            counts += (mid - i + 1);  // 核心的观察
        }
    }

    // 左右剩余元素的复制
    while (i <= mid)
    {
        tmp[k++] = trains[i++];
    }
    while (j <= right)
    {
        tmp[k++] = trains[j++];
    }
    // 复制回原来的数组
    for (int index = left; index <= right; index++)
    {
        trains[index] = tmp[index];
    }

    return counts;
}

int main()
{
    int n;
    cin >> n;

    vector<int> trains(n);
    for (int i = 0; i < n; i++)
    {
        cin >> trains[i];
    }

    vector<int> tmp(n);
    // Above for initialization

    long long reverse = doReverse(trains, tmp, 0, n - 1);
    cout << reverse << endl;

    return 0;
}