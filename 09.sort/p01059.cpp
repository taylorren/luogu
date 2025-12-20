#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> nums;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        nums.insert(tmp);
    }

    int size = nums.size();
    cout << size << endl;

    for (auto n : nums)
    {
        cout << n << " ";
    }

    cout << endl;
}