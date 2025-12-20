#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector<int>& numbers, int l, int r)
{
    if (l >= r)
        return;

    int pivot = numbers[(l + r) / 2];
    int left = l, right = r;

    while (left <= right)
    {
        while (numbers[left] < pivot)
        {
            left++;
        }
        while (numbers[right] > pivot)
        {
            right--;
        }

        if (left <= right)
        {
            swap(numbers[left], numbers[right]);
            left++;
            right--;
        }
    }

    quick_sort(numbers, l, right);
    quick_sort(numbers, left, r);
}

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    quick_sort(numbers, 0, n - 1);

    for (auto k : numbers)
    {
        cout << k << " ";
    }
    cout << endl;

    return 0;
}