#include <bits/stdc++.h>

#include <cctype>
using namespace std;

bool expandable(char left, char right)
{
    if ((islower(left) && isalpha(right)) || (isdigit(left) && isdigit(right)))
    {
        if (right > left)
        {
            return true;
        }
    }

    return false;
}

char getFillChar(char c, int p1)
{
    char fill = c;
    if (p1 == 2 && islower(c))
    {
        fill = toupper(c);
    }
    else if (p1 == 3)
    {
        fill = '*';
    }

    return fill;
}

string getFillString(char fill, int p2)
{
    string tmp;
    for (int i = 0; i < p2; i++)
    {
        tmp += fill;
    }
    return tmp;
}

int main()
{
    string s;
    int p1, p2, p3;

    cin >> p1 >> p2 >> p3;
    cin >> s;

    string result;
    for (int i = 0; i < s.length(); i++)
    {
        if (i > 0 && i < s.length() - 1 && s[i] == '-')
        {
            char left = s[i - 1], right = s[i + 1];
            if (expandable(left, right))
            {
                string tmp;
                if (left == right - 1)
                {
                    continue;
                }
                for (char c = left + 1; c < right; c++)
                {
                    char fill = getFillChar(c, p1);
                    tmp += getFillString(fill, p2);
                }

                if (p3 == 2)
                {
                    reverse(tmp.begin(), tmp.end());
                }
                result += tmp;
            }
            else
            {
                result += '-';
            }
        }
        else
        {
            result += s[i];
        }
    }

    cout << result << endl;
    return 0;
}