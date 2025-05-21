#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

vector<int> references[MAXN];
bool readed[MAXN];
int n, m;

void dfs(int x)
{
    cout<<x<<" ";
    sort(references[x].begin(), references[x].end());
    for(int v: references[x])
    {
        if(!readed[v])
        {
            readed[v]=true;
            dfs(v);
        }
    }
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        cout<<x<<" ";

        sort(references[x].begin(), references[x].end());
        
        for(int i: references[x])
        {
            if(!readed[i])
            {
                readed[i]=true;
                q.push(i); 
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        references[u].push_back(v);
    }
    readed[1]=true;
    dfs(1);
    cout<<endl;
    memset(readed, false, sizeof(readed));
    readed[1]=true;
    bfs(1);
    cout<<endl;

    return 0;
}
