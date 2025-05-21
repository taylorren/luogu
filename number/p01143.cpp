#include <bits/stdc++.h>
using namespace std;

int char_to_digit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}
int main() {
    int from_base, to_base;
    string num;
    cin>>from_base>>num>>to_base;

    int n = num.length();
    int ans = 0;
    int dec=0;

    for (int i = 0; i < n; i++) {
        dec=dec*from_base+char_to_digit(num[i]);
    }

    string res="";
    while (dec) {
        int rem=dec%to_base;
        if (rem < 10) {
            res += to_string(rem);
        }    
        else {
            res += char(rem - 10 + 'A');
        }
        dec/=to_base;
    }
    reverse(res.begin(),res.end());
    if (res=="") {
        cout<<0<<endl;
    }
    else {
        cout<<res<<endl;
    }    
}