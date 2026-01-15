#include <bits/stdc++.h>
using namespace std;

// Returns true is n is a prime
bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

// Count how many 1s in n's binary representation
int countOne(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            count++;
        }
        n /= 2;
    }
    return count;
}

int main()
{
    int n, k;
    cin>>n>>k;

    vector<int> x(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }

    long long count=0;
    long long total=1<<n; // total variations

    for(int current=0;current<total;current++)
    {
        if(countOne(current)==k) // This number has k elements selected
        {
            int sum=0;
            for(int mask=0;mask<n;mask++)
            {
                if(current & (1<<mask))
                {
                    sum+=x[mask];
                }
            }
            if(isPrime(sum))
            {
                count++;
            }
        }
    }

    cout<<count<<endl;
}