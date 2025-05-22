#include <bits/stdc++.h>
using namespace std;

// 改进的高精度乘法函数
string multiply(string num1, int num2) {
    // 处理特殊情况
    if (num1 == "0" || num2 == 0) return "0";
    
    int n = num1.size();
    vector<int> result(n + 11, 0);  // 预留足够空间
    
    // 从低位到高位计算
    for (int i = n - 1; i >= 0; i--) {
        int digit = num1[i] - '0';
        int pos = n - 1 - i;
        int prod = digit * num2 + result[pos];
        result[pos] = prod % 10;
        result[pos + 1] += prod / 10;  // 处理进位
    }
    
    // 处理剩余的进位
    for (int i = n; i < n + 10; i++) {
        if (result[i] >= 10) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }
    
    // 构建结果字符串
    string ans;
    int i = n + 10;
    // 跳过前导零
    while (i >= 0 && result[i] == 0) i--;
    
    // 如果结果为0
    if (i < 0) return "0";
    
    // 转换为字符串
    while (i >= 0) {
        ans += (result[i] + '0');
        i--;
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    // 特殊情况处理
    if (n <= 3) {
        cout << n << endl << n << endl;
        return 0;
    }
    
    vector<int> result;
    string product = "1";  // 使用字符串存储乘积
    
    // 从2开始选择连续的自然数
    int current = 2;
    int sum = 0;
    
    while (sum + current < n) {
        result.push_back(current);
        sum += current;
        product = multiply(product, current);
        current++;
    }
    
    // 计算超出的部分
    int diff = sum + current - n;
    
    if (diff == 0) {
        // 刚好等于n，加入最后一个数
        result.push_back(current);
        product = multiply(product, current);
    } else if (diff == 1) {
        // 超出1，去掉2，将最后一个数加1
        for (int i = 0; i < result.size(); i++) {
            if (result[i] == 2) {
                result.erase(result.begin() + i);
                product = "1";  // 重新计算乘积
                for (int num : result) {
                    product = multiply(product, num);
                }
                break;
            }
        }
        result.push_back(current + 1);
        product = multiply(product, current + 1);
    } else {
        // 超出k (k≠1)，直接去掉等于k的数
        bool found = false;
        for (int i = 0; i < result.size(); i++) {
            if (result[i] == diff) {
                result.erase(result.begin() + i);
                product = "1";  // 重新计算乘积
                for (int num : result) {
                    product = multiply(product, num);
                }
                found = true;
                break;
            }
        }
        
        if (!found) {
            // 如果没有找到等于diff的数，需要特殊处理
            // 这里简化处理，去掉最小的数，调整最大的数
            result.erase(result.begin());
            product = "1";  // 重新计算乘积
            for (int num : result) {
                product = multiply(product, num);
            }
            result.push_back(current);
            product = multiply(product, current);
        } else {
            // 找到了等于diff的数，加入current
            result.push_back(current);
            product = multiply(product, current);
        }
    }
    
    // 按从小到大排序
    sort(result.begin(), result.end());
    
    // 输出结果
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl << product << endl;
    
    return 0;
}