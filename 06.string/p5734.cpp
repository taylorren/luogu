#include <iostream>
#include <string>
using namespace std;

int main()
{
    int q;
    string doc;

    cin >> q;
    cin >> doc;

    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            // 操作1：在文档后面插入字符串
            string str;
            cin >> str;
            doc += str;
            cout << doc << endl;
        }
        else if (op == 2)
        {
            // 操作2：截取文档部分
            int a, b;
            cin >> a >> b;
            doc = doc.substr(a, b);
            cout << doc << endl;
        }
        else if (op == 3)
        {
            // 操作3：在指定位置插入字符串
            int a;
            string str;
            cin >> a >> str;
            doc.insert(a, str);
            cout << doc << endl;
        }
        else if (op == 4)
        {
            // 操作4：查找子串
            string str;
            cin >> str;
            int pos = doc.find(str);
            cout << pos << endl;
        }
    }

    return 0;
}