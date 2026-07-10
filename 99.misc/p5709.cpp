#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, t, s;
    cin>> m >> t >> s;
    int remain=m-ceil(1.0*s/t);
    
    cout<<((remain<=0)?0:remain);
    return 0;
}