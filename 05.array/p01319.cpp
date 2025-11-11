#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<char> output;
    int count;
    bool flag = false;
    int total = n * n;

    while (total > 0)
    {
        cin >> count;
        for (int i = 1; i <= count; i++)
        {
            output.push_back(flag ? '1' : '0');
        }
        flag = !flag;
        total -= count;
    }

    for (int i = 0; i < n*n; i++)
    {
        cout << output[i];
        if ((i+1) % n == 0)
        {
            cout << endl;
        }
    }

    return 0;
}