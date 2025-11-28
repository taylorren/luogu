#include <iostream>
#include <string>

using namespace std;

int main()
{
    // 创建字符到按键次数的映射数组
    int keyPresses[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
                          2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

    string input;
    getline(cin, input);

    int totalPresses = 0;
    for (char c : input)
    {
        if (c == ' ')
        {
            totalPresses++;
        }
        else
        {
            totalPresses += keyPresses[c - 'a'];
        }
    }

    cout << totalPresses << endl;
    return 0;
}