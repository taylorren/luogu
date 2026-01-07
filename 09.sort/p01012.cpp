#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b)
{
    return a + b > b + a;
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

    sort(nums.begin(), nums.end(), cmp);

    string result = "";
    for (const string &num : nums)
    {
        result += num;
    }

    cout << result << endl;

    return 0;
}