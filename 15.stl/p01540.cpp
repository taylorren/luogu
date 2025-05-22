#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;
bool in_queue[N];
int main()
{
    cin >> m >> n;
    int res = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!in_queue[x])
        {
            res++;
            if (q.size() == m)
            {
                in_queue[q.front()] = false;
                q.pop();
            }
            q.push(x);
            in_queue[x] = true;
        }
    }
    cout << res << endl;
    return 0;
}