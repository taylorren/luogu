#include <bits/stdc++.h>
using namespace std;

int countVK(string s, int len)
{
    int count = 0;
    for (int i = 0; i < len - 1; i++)
    {
        if (s[i] == 'V' && s[i + 1] == 'K')
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int count = countVK(s, n);
    for (int i = 0; i < n; i++)
    {
        string temp_s=s;
        s[i] == 'V' ? temp_s[i] = 'K' : temp_s[i]='V';
        
        int temp = countVK(temp_s, n);
        if (temp > count)
        {
            count = temp;
        }
    }

    cout << count;
}
