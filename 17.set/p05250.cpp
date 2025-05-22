#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 使用set存储木材长度
    set<int> woods;
    
    while (n--) {
        int op, length;
        cin >> op >> length;
        
        if (op == 1) {  // 进货操作
            if (woods.count(length)) {
                cout << "Already Exist" << endl;
            } else {
                woods.insert(length);
            }
        } else {  // 出货操作
            if (woods.empty()) {
                cout << "Empty" << endl;
                continue;
            }
            
            // 找到大于等于length的第一个元素
            auto it = woods.lower_bound(length);
            
            // 如果找到了精确匹配
            if (it != woods.end() && *it == length) {
                cout << length << endl;
                woods.erase(it);
                continue;
            }
            
            // 找到最接近的元素
            int closest;
            if (it == woods.begin()) {
                closest = *it;
            } else if (it == woods.end()) {
                closest = *(--it);
            } else {
                int higher = *it;
                int lower = *(--it);
                // 如果两个数到length的距离相等，选择较小的
                closest = (higher - length < length - lower) ? higher : lower;
            }
            
            cout << closest << endl;
            woods.erase(closest);
        }
    }
    
    return 0;
}