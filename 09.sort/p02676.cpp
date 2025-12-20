#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, shelf_height;
    cin >> n >> shelf_height;

    vector<int> cows(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end());
    reverse(cows.begin(), cows.end());

    int count = 0, current_height = 0;
    while (current_height < shelf_height)
    {
        current_height += cows[count];
        count++;
    }

    cout << count << endl;

    return 0;
}