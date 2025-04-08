#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string n;
    int k;
    cin >> n >> k;

    // 如果需要删除的数字个数等于原数字长度，直接输出0
    if (k >= n.length())
    {
        cout << "0" << endl;
        return 0;
    }

    vector<char> stack;  // 用栈来存储结果

    // 从左到右扫描数字
    for (char digit : n)
    {
        // 如果当前数字比栈顶元素小，且还有删除次数，则删除栈顶元素
        while (!stack.empty() && stack.back() > digit && k > 0)
        {
            stack.pop_back();
            k--;
        }
        stack.push_back(digit);
    }

    // 如果还有删除次数，从栈的末尾删除
    while (k > 0 && !stack.empty())
    {
        stack.pop_back();
        k--;
    }

    // 构建结果字符串，去除前导零
    string result;
    bool leadingZero = true;
    for (char digit : stack)
    {
        if (leadingZero && digit == '0')
        {
            continue;  // 跳过前导零
        }
        leadingZero = false;
        result += digit;
    }

    // 如果结果为空，输出0
    if (result.empty())
    {
        cout << "0" << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}