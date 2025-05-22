#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    char val;
    char left;
    char right;
    Node(char v = '*', char l = '*', char r = '*') : val(v), left(l), right(r) {}
};

unordered_map<char, Node> tree;

// 前序遍历：根->左->右
void preorder(char root) {
    if (root == '*') return;
    
    cout << root;  // 输出当前节点
    preorder(tree[root].left);   // 遍历左子树
    preorder(tree[root].right);  // 遍历右子树
}

int main() {
    int n;
    cin >> n;
    
    char root, l, r;
    // 第一行是根节点
    cin >> root >> l >> r;
    tree[root] = Node(root, l, r);
    char firstRoot = root;  // 保存根节点
    
    // 读入其余节点
    for (int i = 1; i < n; i++) {
        cin >> root >> l >> r;
        tree[root] = Node(root, l, r);
    }
    
    // 输出前序遍历结果
    preorder(firstRoot);
    cout << endl;
    
    return 0;
}