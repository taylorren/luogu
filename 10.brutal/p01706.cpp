#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }

    do
    {
        for (int i = 0; i < n; i++)
        {
            cout << setw(5) << nums[i];
        }
        cout << endl;

    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}