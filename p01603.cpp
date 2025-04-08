#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string dic[30] = {"zero","one","two","three","four","five","six","seven","eight","nine",
                      "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen",
                      "seventeen","eighteen","nineteen","twenty","a","both","another",
                      "first","second","third"};
    string di[30] = {"00","01","04","09","16","25","36","49","64","81","00","21","44","69",
                     "96","25","56","89","24","61","00","01","04","01","01","04","09"};
    
    string a;
    getline(cin, a);
    vector<string> nums;
    
    string word;
    int pos = 0;
    while ((pos = a.find(" ")) != string::npos) {
        word = a.substr(0, pos);
        a = a.substr(pos + 1);
        
        for(int i = 0; i < 27; i++) {
            if(word == dic[i] && di[i] != "00") {
                nums.push_back(di[i]);
                break;
            }
        }
    }
    
    if(!a.empty()) {
        if(a.back() == '.') a.pop_back();
        for(int i = 0; i < 27; i++) {
            if(a == dic[i] && di[i] != "00") {
                nums.push_back(di[i]);
                break;
            }
        }
    }
    
    if(nums.empty()) {
        cout << 0 << endl;
        return 0;
    }
    
    sort(nums.begin(), nums.end());
    
    string result = "";
    for(const string& s : nums) result += s;
    while(result[0] == '0' && result.length() > 1) result.erase(0, 1);
    
    cout << result << endl;
    return 0;
}