#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count;
    cin >> count;
    
    // 创建一个布尔数组来标记差值是否出现
    vector<bool> diff(count, false);
    
    int prev, curr;
    cin >> prev;
    
    if(count == 1)
    {
        cout << "Jolly" << endl;
        return 0;
    }
    
    for(int i = 1; i < count; i++)
    {
        cin >> curr;
        int pos = abs(curr - prev);
        
        // 检查差值是否在有效范围内
        if(pos > 0 && pos < count)
        {
            diff[pos] = true;
        }
        
        prev = curr;
    }
    
    // 检查是否所有的差值都出现了
    bool isJolly = true;
    for(int i = 1; i < count; i++)
    {
        if(!diff[i])
        {
            isJolly = false;
            break;
        }
    }
    
    if(isJolly)
        cout << "Jolly" << endl;
    else
        cout << "Not jolly" << endl;
    
    return 0;
}