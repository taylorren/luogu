#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string expand(istringstream &iss)
{
    string key = "", x;
    char c;
    int num;
    
    while(iss >> c)
    {
        if(c == '[')
        {
            iss >> num;
            x = expand(iss);
            
            while(num--)
                key += x;
        }
        else if(c == ']')
            return key;
        else 
            key += c;
    }
    
    return key; // 处理输入结束的情况
}

int main(void)
{
    string input;
    getline(cin, input); // 一次性读取整行输入
    
    istringstream iss(input);
    cout << expand(iss);
    
    return 0;
}
