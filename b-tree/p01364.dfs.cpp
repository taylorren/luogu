#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
int n, ans=1'000'000'000, vis[MAXN];

struct Node {
    int population;
    int left;
    int right;
    int father;
} t[MAXN];

int cal(int x, int d) {
    if(!x||vis[x])
    {
        return 0;
    }

    vis[x]=1;
    return      cal(t[x].left, d+1) + 
                cal(t[x].right, d+1) +
                cal(t[x].father, d+1) +
                t[x].population * d;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i].population >> t[i].left >> t[i].right;
    }
    for (int i = 1; i <= n; ++i) {
        t[t[i].left].father=i;
        t[t[i].right].father=i;
    }

    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        ans=min(ans, cal(i, 0));    
    }

    cout << ans << endl;
    return 0;
}

