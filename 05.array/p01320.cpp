#include <bits/stdc++.h>
using namespace std;

int main()
{
    string all = "";
    string line;
    
    // Read all lines
    while (cin >> line)
    {
        all += line;
    }
    
    // Calculate n (side length)
    int n = sqrt(all.length());
    cout << n << " ";
    
    // Count consecutive 0s and 1s
    char current = '0';
    int count = 0;
    
    for (int i = 0; i < all.length(); i++)
    {
        if (all[i] == current)
        {
            count++;
        }
        else
        {
            cout << count << " ";
            current = all[i];
            count = 1;
        }
    }
    
    // Output the last count
    cout << count << endl;
    
    return 0;
}
