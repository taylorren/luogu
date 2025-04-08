#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=0, tmp, nums[110];
    do
    {
        cin>>tmp;
        nums[n] = tmp;
        n++;
    } while (tmp!= 0);

    n--;
    while(n--)
    {
        cout<<nums[n]<<' ';
    }
    return 0;
}