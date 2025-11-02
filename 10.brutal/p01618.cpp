#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    bool found = false;
    
    // 枚举所有可能的排列
    int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    do {
        // 构造三个三位数
        int num1 = nums[0] * 100 + nums[1] * 10 + nums[2];
        int num2 = nums[3] * 100 + nums[4] * 10 + nums[5];
        int num3 = nums[6] * 100 + nums[7] * 10 + nums[8];
        
        // 检查比例是否符合要求
        if (num1 * B == num2 * A && num1 * C == num3 * A) {
            cout << num1 << " " << num2 << " " << num3 << endl;
            found = true;
        }
    } while (next_permutation(nums, nums + 9));
    
    if (!found) {
        cout << "No!!!" << endl;
    }
    
    return 0;
}