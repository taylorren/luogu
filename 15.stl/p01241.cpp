#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();
    vector<bool> matched(n, false);  // 记录每个字符是否已匹配
    stack<int> st;                   // 存储未匹配的左括号的位置

    // 第一步：找出能够匹配的括号对
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[')
        {
            // 左括号入栈
            st.push(i);
        }
        else
        {
            // 右括号，尝试匹配
            if (!st.empty())
            {
                int top_pos = st.top();
                // 检查是否匹配（小括号匹配小括号，中括号匹配中括号）
                if ((s[i] == ')' && s[top_pos] == '(') ||
                    (s[i] == ']' && s[top_pos] == '['))
                {
                    matched[i] = true;        // 标记右括号已匹配
                    matched[top_pos] = true;  // 标记左括号已匹配
                    st.pop();                 // 弹出已匹配的左括号
                }
            }
        }
    }

    // 第二步：构建结果字符串
    string result = "";
    for (int i = 0; i < n; i++)
    {
        // 如果是右括号且未匹配，先添加匹配的左括号
        if ((s[i] == ')' || s[i] == ']') && !matched[i])
        {
            result += (s[i] == ')' ? '(' : '[');
        }
        
        result += s[i];  // 添加原字符
        
        // 如果是左括号且未匹配，添加匹配的右括号
        if ((s[i] == '(' || s[i] == '[') && !matched[i])
        {
            result += (s[i] == '(' ? ')' : ']');
        }
    }

    cout << result << endl;
    return 0;
}