#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int s, e;
    cin >> s >> e;

    int years=0;
    vector<int> leapYears;

    for (int i = s; i <= e; i++)
    {
        if (isLeapYear(i))
        {
            leapYears.push_back(i);
            years++;
        }
    }

    cout<< years<<endl;
    for(auto y:leapYears)
    {
        cout<<y<<" ";
    }

    return 0;
}