#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        unordered_set<int> seen;
        vector<int> result;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            // 只在第一次出现时加入结果
            if (seen.insert(x).second)
                result.push_back(x);
        }
        for (size_t i = 0; i < result.size(); ++i)
        {
            if (i) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}