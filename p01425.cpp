#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    // 将所有时间转换为分钟
    int start_minutes = a * 60 + b;
    int end_minutes = c * 60 + d;
    
    // 计算时间差（单位：分钟）
    int diff_minutes = end_minutes - start_minutes;
    
    // 转换回小时和分钟
    int hours = diff_minutes / 60;
    int minutes = diff_minutes % 60;
    
    cout << hours << " " << minutes << endl;
    
    return 0;
}