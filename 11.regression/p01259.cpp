#include <iostream>
#include <string>
using namespace std;

// 打印棋盘状态
void printBoard(const string& board)
{
    cout << board << endl;
}

// 解决基本情况：4个白子和4个黑子
void solveBase(string suffix = "", bool skipInitial = false)
{
    // 初始状态，只在非递归调用时输出
    if (!skipInitial) {
        printBoard("oooo****--" + suffix);
    }

    // 标准步骤
    printBoard("ooo--***o*" + suffix);
    printBoard("ooo*o**--*" + suffix);
    printBoard("o--*o**oo*" + suffix);
    printBoard("o*o*o*--o*" + suffix);
    printBoard("--o*o*o*o*" + suffix);
}

// 递归解决n白n黑的问题
// skipInitial参数用于控制是否跳过输出初始状态
void solveRecursive(int n, string suffix = "", bool skipInitial = false)
{
    // 基本情况：n=4
    if (n == 4)
    {
        solveBase(suffix, skipInitial);
        return;
    }

    // 初始状态，只在非递归调用时输出
    string whites(n, 'o');
    string blacks(n, '*');
    if (!skipInitial)
    {
        printBoard(whites + blacks + "--" + suffix);
    }

    // 第一步：移动第n个白子和第(n+1)个黑子到最右边的空位
    string step1 = whites.substr(0, n - 1) + "--" + blacks.substr(0, n - 1) +
                   "o*" + suffix;
    printBoard(step1);

    // 第二步：将问题转化为(n-1)白(n-1)黑的问题，但保留最后的o*
    string step2 = whites.substr(0, n - 1) + blacks.substr(0, n - 1) + "--" +
                   "o*" + suffix;
    printBoard(step2);

    // 递归解决(n-1)白(n-1)黑的问题，但保留最后的o*
    // 注意设置skipInitial=true，表示跳过输出初始状态
    solveRecursive(n - 1, "o*" + suffix, true);
}

int main()
{
    int n;
    cin >> n;

    if (n < 4)
    {
        cout << "n must be at least 4" << endl;
        return 1;
    }

    solveRecursive(n);

    return 0;
}