#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vars[3] = {0, 0, 0};  // vars[0]=a, vars[1]=b, vars[2]=c
    string input;
    getline(cin, input);

    for (int i = 0; i < input.size(); i++)
    {
        // 找到变量名
        if (input[i] >= 'a' && input[i] <= 'c')
        {
            int var_index = input[i] - 'a';  // a->0, b->1, c->2
            i += 3;  // 跳过 :=

            // 解析值
            char value = input[i];
            int result;
            
            if (value >= '0' && value <= '9')
            {
                result = value - '0';
            }
            else
            {
                result = vars[value - 'a'];  // 从数组读取变量值
            }

            // 赋值
            vars[var_index] = result;
        }
    }

    cout << vars[0] << " " << vars[1] << " " << vars[2] << endl;
    return 0;
}