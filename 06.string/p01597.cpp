#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, int> variables = {{'a', 0}, {'b', 0}, {'c', 0}};
    string input;
    getline(cin, input);
    
    size_t pos = 0;
    while (pos < input.size()) {
        // 解析变量名
        char var = input[pos];
        pos += 3; // 跳过:=
        
        // 解析值
        char value = input[pos];
        if (isdigit(value)) {
            variables[var] = value - '0';
        } else {
            variables[var] = variables[value];
        }
        
        pos += 2; // 跳过;和可能的空格
    }
    
    cout << variables['a'] << " " << variables['b'] << " " << variables['c'] << endl;
    return 0;
}