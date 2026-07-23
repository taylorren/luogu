#include <bits/stdc++.h>
using namespace std;

const int GRID=13+1;
int n;
int col_place[GRID]; // col placing for one queen a row
int print_count=0;

void print_solution()
{
    if(print_count>=4)
    {
        return;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<col_place[i]<<" ";
    }
    cout<<endl;
}

bool can_place(int row, int col)
{
    for(int i=1;i<row;i++)
    {
        if(col_place[i]==col || abs(col_place[i]-col)==abs(i-row))
            return false;
    }
    return true;
}
bool dfs(int row)
{
    if(row>n)
    {
        print_count++;
        print_solution();
        return true;
    }

    for(int i=1;i<=n;i++)
    {
        if(can_place(row, i))
        {
            col_place[row]=i;
            dfs(row+1);
            col_place[row]=0;
        }
    }
    return true;
}


int main()
{
    cin>>n;

    dfs(1);
    cout<<print_count<<endl;

}