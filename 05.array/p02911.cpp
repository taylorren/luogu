#include <bits/stdc++.h>
using namespace std;

int main()
{
    int S1, S2, S3;
    cin>>S1>>S2>>S3; //三个骰子的面数

    vector<int> sums(S1+S2+S3+1, 0);

    for(int i=1; i<=S1; i++)
    {
        for(int j=1; j<=S2; j++)
        {
            for(int k=1; k<=S3; k++)
            {
                sums[i+j+k]++;
            }
        }
    }

    int max_count = *max_element(sums.begin(), sums.end());
    for(int i=0;i<S1+S2+S3+1; i++)
    {
        if(sums[i] == max_count)
        {
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}