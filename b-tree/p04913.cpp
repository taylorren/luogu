#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int left;
    int right;
};

int maxDepth(const vector<Node>& tree, int root)
{
    if (root == 0)
    {
        return 0;  // 空节点返回0
    }
    int leftDepth = maxDepth(tree, tree[root].left);
    int rightDepth = maxDepth(tree, tree[root].right);
    return max(leftDepth, rightDepth) + 1;  // 加1计算当前节点
}

int main()
{
    int n;
    cin >> n;

    vector<Node> tree(n + 1);  // 使用1-based索引

    // 读取每个节点的子节点
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i].left >> tree[i].right;
    }

    // 计算最大深度
    int depth = maxDepth(tree, 1);

    cout << depth << endl;

    return 0;
}