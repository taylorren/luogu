#include <iostream>
#include <vector>
using namespace std;

// 计算逆序对数量的函数
long long countInversions(vector<int>& arr, vector<int>& temp, int left,
                          int right)
{
    // 基本情况：只有一个元素时没有逆序对
    if (left >= right)
        return 0;

    // 分治：将数组分成两半
    int mid = left + (right - left) / 2;

    // 递归计算左半部分和右半部分的逆序对
    long long inversions = countInversions(arr, temp, left, mid) +
                           countInversions(arr, temp, mid + 1, right);

    // 合并两个已排序的子数组，并计算跨越中点的逆序对
    int i = left;     // 左半部分的起始索引
    int j = mid + 1;  // 右半部分的起始索引
    int k = left;     // 临时数组的起始索引

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            // 当右半部分的元素小于左半部分的元素时，形成逆序对
            // 左半部分从i到mid的所有元素都与arr[j]形成逆序对
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }

    // 复制剩余元素
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // 将临时数组中的元素复制回原数组
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inversions;
}

int main()
{
    int n;
    cin >> n;

    vector<int> train(n);
    for (int i = 0; i < n; i++)
    {
        cin >> train[i];
    }

    vector<int> temp(n);
    long long rotations = countInversions(train, temp, 0, n - 1);

    cout << rotations << endl;

    return 0;
}