#include <climits>
#include <iostream>
using namespace std;

const int MAXN = 100010;

// 二叉搜索树节点结构
struct Node
{
    int left;   // 左子节点索引
    int right;  // 右子节点索引
    int size;   // 子树大小
    int value;  // 节点值
    int count;  // 当前值的数量

    Node() : left(0), right(0), size(0), value(0), count(0) {}
    Node(int v) : left(0), right(0), size(1), value(v), count(1) {}
};

Node tree[MAXN];    // 存储所有节点
int root = 0;       // 根节点索引
int nodeCount = 0;  // 节点总数

// 更新节点的子树大小
void updateSize(int node)
{
    if (node == 0)
        return;
    tree[node].size = tree[tree[node].left].size + tree[tree[node].right].size + tree[node].count;
}

// 插入一个数
void insert(int &node, int value)
{
    if (node == 0)
    {
        node = ++nodeCount;
        tree[node] = Node(value);
        return;
    }

    if (value == tree[node].value)
    {
        tree[node].count++;
    }
    else if (value < tree[node].value)
    {
        insert(tree[node].left, value);
    }
    else
    {
        insert(tree[node].right, value);
    }

    updateSize(node);
}

// 查询数x的排名（小于x的数的个数+1）
int getRank(int node, int value)
{
    if (node == 0)
        return 1;

    if (value <= tree[node].value)
    {
        return getRank(tree[node].left, value);
    }
    else
    {
        return getRank(tree[node].right, value) + tree[tree[node].left].size +
               tree[node].count;
    }
}

// 查询排名为rank的数
int getByRank(int node, int rank)
{
    if (node == 0)
        return -1;

    int leftSize = tree[tree[node].left].size;

    if (rank <= leftSize)
    {
        return getByRank(tree[node].left, rank);
    }
    else if (rank <= leftSize + tree[node].count)
    {
        return tree[node].value;
    }
    else
    {
        return getByRank(tree[node].right, rank - leftSize - tree[node].count);
    }
}

// 查询x的前驱（小于x且最大的数）
int getPredecessor(int node, int value)
{
    if (node == 0)
        return INT_MIN;

    if (tree[node].value >= value)
    {
        return getPredecessor(tree[node].left, value);
    }
    else
    {
        int rightResult = getPredecessor(tree[node].right, value);
        return (rightResult == INT_MIN) ? tree[node].value : rightResult;
    }
}

// 查询x的后继（大于x且最小的数）
int getSuccessor(int node, int value)
{
    if (node == 0)
        return INT_MAX;

    if (tree[node].value <= value)
    {
        return getSuccessor(tree[node].right, value);
    }
    else
    {
        int leftResult = getSuccessor(tree[node].left, value);
        return (leftResult == INT_MAX) ? tree[node].value : leftResult;
    }
}

int main()
{
    int q, op, x;
    cin >> q;

    while (q--)
    {
        cin >> op >> x;

        if (op == 1)
        {
            // 查询x的排名
            cout << getRank(root, x) << endl;
        }
        else if (op == 2)
        {
            // 查询排名为x的数
            cout << getByRank(root, x) << endl;
        }
        else if (op == 3)
        {
            // 查询x的前驱
            int result = getPredecessor(root, x);
            if (result == INT_MIN)
                result = -2147483647;
            cout << result << endl;
        }
        else if (op == 4)
        {
            // 查询x的后继
            int result = getSuccessor(root, x);
            if (result == INT_MAX)
                result = 2147483647;
            cout << result << endl;
        }
        else if (op == 5)
        {
            // 插入x
            insert(root, x);
        }
    }

    return 0;
}