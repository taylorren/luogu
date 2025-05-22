#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> result;  // 存储后序遍历结果

// 判断字符串类型（B/I/F）
char getType(const string& s)
{
    bool has0 = false, has1 = false;
    for (char c : s)
    {
        if (c == '0')
            has0 = true;
        if (c == '1')
            has1 = true;
    }

    if (has0 && has1)
        return 'F';
    if (has0)
        return 'B';
    return 'I';
}

// 构建FBI树并存储后序遍历结果
void buildAndTraverse(const string& s)
{
    int len = s.length();
    if (len == 0)
        return;

    // 递归构建左右子树
    if (len > 1)
    {
        int mid = len / 2;
        buildAndTraverse(s.substr(0, mid));          // 左子树
        buildAndTraverse(s.substr(mid, len - mid));  // 右子树
    }

    // 将当前节点加入结果向量（后序遍历：左->右->根）
    result.push_back(getType(s));
}

int main()
{
    int n;
    string s;
    cin >> n >> s;

    buildAndTraverse(s);
    
    // 输出结果
    for (char c : result)
    {
        cout << c;
    }
    cout << endl;

    return 0;
}