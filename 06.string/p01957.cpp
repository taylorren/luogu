#include <iostream>
#include <string>
using namespace std;

int main() {
    int i;
    cin >> i;
    
    char op = ' '; // 记录上一次的运算类型
    
    for (int j = 0; j < i; j++) {
        string input;
        int a, b;
        
        // 读取第一个输入
        cin >> input;
        
        // 判断是否为运算符
        if (input == "a" || input == "b" || input == "c") {
            op = input[0]; // 更新运算类型
            cin >> a >> b;  // 读取两个运算数
        } else {
            // 如果不是运算符，则使用上一次的运算类型
            a = stoi(input);
            cin >> b;
        }
        
        // 计算结果
        int result;
        string equation;
        
        if (op == 'a') { // 加法
            result = a + b;
            equation = to_string(a) + "+" + to_string(b) + "=" + to_string(result);
        } else if (op == 'b') { // 减法
            result = a - b;
            equation = to_string(a) + "-" + to_string(b) + "=" + to_string(result);
        } else if (op == 'c') { // 乘法
            result = a * b;
            equation = to_string(a) + "*" + to_string(b) + "=" + to_string(result);
        }
        
        // 输出运算式和长度
        cout << equation << endl;
        cout << equation.length();
        
        // 除了最后一个结果外，其他结果后面都要加换行符
        if (j < i - 1) {
            cout << endl;
        }
    }
    
    return 0;
}