#include <bits/stdc++.h>

#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int n = s.length();

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ' || s[i] == '\n')
        {
            continue;
        }
        else
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}