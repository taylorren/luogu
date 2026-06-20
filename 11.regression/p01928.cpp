#include <bits/stdc++.h>
using namespace std;

string expand(istringstream& iss)
{
    string key="", part;
    char c;
    int num;

    while(iss>>c)
    {
        if(c=='[') // Start a new iteration
        {
            iss>>num; // Repetition count
            part=expand(iss); // Recursively expand the inner part
            for(int i=0; i<num; i++)
            {
                key+=part; // Append the expanded part 'num' times
            }
        }
        else if(c==']') // End of the current iteration
        {
            return key; // Return the expanded string for this level
        }
        else
        {
            key+=c; // Append regular characters to the key
        }
    }
    return key; // Return the final expanded string
}

int main()
{
    string s;
    getline(cin, s);
    istringstream iss(s);

    string final=expand(iss);
    cout<<final<<endl;

    return 0;
}