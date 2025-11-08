#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 创建鱼的数组，索引从1开始使用
    vector<int> fishes(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> fishes[i];
    }

    for(int i = 1; i <= n; i++)
    {
        int count = 0;  // 当前鱼比过的鱼的数量（可爱值更高）
        
        // 向左扫描所有在当前鱼左边的鱼
        for(int j = i-1; j >= 1; j--)
        {
            // 如果当前鱼的可爱值比左边的鱼高，就比过了它
            if(fishes[i] > fishes[j])
            {
                count++;
            }
        }
        cout << count << " ";
    }

    return 0;
}