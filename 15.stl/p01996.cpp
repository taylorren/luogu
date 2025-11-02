#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;

    cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() != 1)
    {
        for (int i = 1; i < k; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout<<q.front()<<" ";
        q.pop();
    }
    cout << q.front() << endl;

    return 0;
}

// 本题类似http://noi.openjudge.cn/ch0302/1748/（约瑟夫问题）