#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> in_map;

void buildTree(string& postorder, int postStart, int postEnd, string& inorder,
               int inStart, int inEnd, string& preorder)
{
    if (postStart > postEnd)
        return;

    // 根节点是后序遍历的最后一个元素
    char root = postorder[postEnd];
    
    // 将根节点加入前序遍历
    preorder += root;

    // 在中序遍历中找到根节点的位置
    int inRoot = in_map[root];

    // 计算左子树的大小
    int leftSize = inRoot - inStart;

    // 递归构建左子树
    buildTree(postorder, postStart, postStart + leftSize - 1, inorder, inStart,
              inRoot - 1, preorder);

    // 递归构建右子树
    buildTree(postorder, postStart + leftSize, postEnd - 1, inorder, inRoot + 1,
              inEnd, preorder);
}

string getPreorder(string& postorder, string& inorder)
{
    // 构建中序遍历的字符到索引的映射
    for (int i = 0; i < inorder.size(); i++)
    {
        in_map[inorder[i]] = i;
    }

    string preorder = "";
    buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, preorder);
    return preorder;
}

int main()
{
    string inorder, postorder;
    cin >> inorder >> postorder;

    string preorder = getPreorder(postorder, inorder);
    cout << preorder << endl;

    return 0;
}