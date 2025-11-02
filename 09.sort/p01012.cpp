#include <bits/stdc++.h>
using namespace std;

// 自定义排序规则
bool compare(const string &a, const string &b)
{
    return a + b > b + a;  // 比较a+b和b+a的大小
}

int main()
{
    int n;
    cin >> n;

    vector<string> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // 按照自定义规则排序
    sort(nums.begin(), nums.end(), compare);

    // 拼接结果
    string result = "";
    for (const string &num : nums)
    {
        result += num;
    }

    // 输出结果
    cout << result << endl;

    return 0;
}