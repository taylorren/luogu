#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> in_map;

void buildTree(string& preorder, int preStart, int preEnd, string& inorder,
               int inStart, int inEnd, string& postorder)
{
    if (preStart > preEnd)
        return;

    // 根节点是前序遍历的第一个元素
    char root = preorder[preStart];

    // 在中序遍历中找到根节点的位置
    int inRoot = in_map[root];

    // 计算左子树的大小
    int leftSize = inRoot - inStart;

    // 递归构建左子树
    buildTree(preorder, preStart + 1, preStart + leftSize, inorder, inStart,
              inRoot - 1, postorder);

    // 递归构建右子树
    buildTree(preorder, preStart + leftSize + 1, preEnd, inorder, inRoot + 1,
              inEnd, postorder);

    // 后序遍历：最后访问根节点
    postorder += root;
}

string getPostorder(string& preorder, string& inorder)
{
    // 构建中序遍历的字符到索引的映射
    for (int i = 0; i < inorder.size(); i++)
    {
        in_map[inorder[i]] = i;
    }

    string postorder = "";
    buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1,
              postorder);
    return postorder;
}

int main()
{
    string inorder, preorder;
    cin >> inorder;
    cin >> preorder;

    string postorder = getPostorder(preorder, inorder);
    cout << postorder << endl;

    return 0;
}