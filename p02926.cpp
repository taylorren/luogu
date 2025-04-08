#include <bits/stdc++.h>
using namespace std;

const int MAX=1'000'010;

int n, a[MAX], c[MAX], w[MAX];

/**
 * @brief Main function.
 *
 * Reads in n numbers from standard input and outputs, for each number, the
 * number of its divisors (excluding itself) on a new line.
 *
 * @return 0 if successful.
 */
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[a[i]]++;
    }

    for(int i=1;i<=1'000'000;i++)
    {
        for(int j=i;j<=1'000'000;j+=i)
        {
            w[j]+=c[i];
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<w[a[i]]-1<<' '<<endl;
    }

    return 0;
}