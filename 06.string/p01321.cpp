#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int boy_count = 0;
    int girl_count = 0;
    
    // 统计boy：考虑所有可能组合
    for(int i = 0; i < s.length(); i++) {
        // 检查三字母组合
        if(i + 2 < s.length() && s[i] == 'b' && s[i+1] == 'o' && s[i+2] == 'y') {
            boy_count++;
            s[i] = s[i+1] = s[i+2] = '.';
            continue;
        }
        // 检查两字母组合
        if(i + 1 < s.length() && 
           ((s[i] == 'b' && s[i+1] == 'o') || 
            (s[i] == 'o' && s[i+1] == 'y'))) {
            boy_count++;
            s[i] = s[i+1] = '.';
            continue;
        }
        // 检查单字母
        if(s[i] == 'b' || s[i] == 'o' || s[i] == 'y') {
            boy_count++;
            s[i] = '.';
        }
    }
    
    // 统计girl：考虑所有可能组合
    for(int i = 0; i < s.length(); i++) {
        // 检查四字母组合
        if(i + 3 < s.length() && s[i] == 'g' && s[i+1] == 'i' && s[i+2] == 'r' && s[i+3] == 'l') {
            girl_count++;
            s[i] = s[i+1] = s[i+2] = s[i+3] = '.';
            continue;
        }
        // 检查三字母组合
        if(i + 2 < s.length() && 
           ((s[i] == 'g' && s[i+1] == 'i' && s[i+2] == 'r') || 
            (s[i] == 'i' && s[i+1] == 'r' && s[i+2] == 'l'))) {
            girl_count++;
            s[i] = s[i+1] = s[i+2] = '.';
            continue;
        }
        // 检查两字母组合
        if(i + 1 < s.length() && 
           ((s[i] == 'g' && s[i+1] == 'i') || 
            (s[i] == 'i' && s[i+1] == 'r') || 
            (s[i] == 'r' && s[i+1] == 'l'))) {
            girl_count++;
            s[i] = s[i+1] = '.';
            continue;
        }
        // 检查单字母
        if(s[i] == 'g' || s[i] == 'i' || s[i] == 'r' || s[i] == 'l') {
            girl_count++;
            s[i] = '.';
        }
    }
    
    cout << boy_count << endl;
    cout << girl_count << endl;
    
    return 0;
}