#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isValidStackSequence(vector<int>& pushed, vector<int>& popped)
{
    stack<int> st;
    int j = 0;  // 指向popped序列的索引

    for (int i = 0; i < pushed.size(); i++)
    {
        // 将当前元素入栈
        st.push(pushed[i]);

        // 检查栈顶元素是否与出栈序列当前元素匹配
        while (!st.empty() && st.top() == popped[j])
        {
            st.pop();
            j++;
        }
    }

    // 如果栈为空，说明所有元素都能按照出栈序列的顺序出栈
    return st.empty();
}

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        int n;
        cin >> n;

        vector<int> pushed(n), popped(n);

        // 读取入栈序列
        for (int i = 0; i < n; i++)
        {
            cin >> pushed[i];
        }

        // 读取出栈序列
        for (int i = 0; i < n; i++)
        {
            cin >> popped[i];
        }

        // 判断是否是有效的栈序列
        if (isValidStackSequence(pushed, popped))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}