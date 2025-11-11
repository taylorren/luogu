#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        numbers[i]=x;
    }
    sort(numbers.begin(), numbers.end());
    int count = 0;
    
    // 从大到小遍历，每个数作为"和"
    for (int k = n - 1; k >= 0; k--)
    {
        int target = numbers[k];
        int i = 0, j = k - 1;
        
        // 双指针查找两个加数
        while (i < j)
        {
            int sum = numbers[i] + numbers[j];
            if (sum == target)
            {
                count++;
                break;
            }
            else if (sum < target)
            {
                i++;  // 和太小，左指针右移
            }
            else
            {
                j--;  // 和太大，右指针左移
            }
        }
    }
    cout << count << endl;

    return 0;
}