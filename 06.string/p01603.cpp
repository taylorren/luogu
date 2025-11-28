#include <bits/stdc++.h>
using namespace std;

// 20个英文单词表示数字1-20,6个其他单词
map<string, string> converts;

void init()
{
    converts["one"]="01";
    converts["two"]="04";
    converts["three"]="09";
    converts["four"]="16";
    converts["five"]="25";
    converts["six"]="36";
    converts["seven"]="49";
    converts["eight"]="64";
    converts["nine"]="81";
    converts["ten"]="00";
    converts["eleven"]="21";
    converts["twelve"]="44";
    converts["thirteen"]="69";
    converts["fourteen"]="96";
    converts["fifteen"]="25";
    converts["sixteen"]="56";
    converts["seventeen"]="89";
    converts["eighteen"]="24";
    converts["nineteen"]="61";
    converts["twenty"]="00";

    converts["a"]="01";
    converts["both"]="04";
    converts["another"]="01";
    converts["first"]="01";
    converts["second"]="04";
    converts["third"]="09";
}


string strip_leading_zeroes(string output)
{
    while(output[0]=='0')
    {
        output=output.substr(1);
    }
    return output;
}


int main()
{
    init();
    string input;
    getline(cin, input);

    stringstream ss(input);
    string word;
    vector<string> output;
    while(ss>>word)
    {
        if(word[word.length()-1]=='.')
        {
            word=word.substr(0, word.length()-1);
        }
        
        if(converts.find(word)!=converts.end())
        {
            output.push_back(converts[word]);
        }
    }
    sort(output.begin(), output.end());
    string final_output="";
    for(int i=0; i<output.size(); i++)
    {
        final_output+=output[i];
    }
    if(final_output.length()>0)
    {
        cout<<strip_leading_zeroes(final_output)<<endl;
    }
    else 
    {
        cout<<"0"<<endl;
    }
    return 0;    
}


