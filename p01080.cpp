#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1010;
const int BASE = 10000; // 基数为10000，每个数组元素存储4位数字

// 高精度整数类
class BigInteger {
private:
    int digits[MAXN * 4]; // 存储数字，每个元素存储4位数字
    int length;           // 数字的长度

public:
    // 构造函数
    BigInteger() {
        memset(digits, 0, sizeof(digits));
        length = 0;
    }

    // 赋值运算符（整数）
    BigInteger& operator=(int num) {
        memset(digits, 0, sizeof(digits));
        length = 0;

        if (num == 0) {
            length = 1;
            return *this;
        }

        while (num > 0) {
            digits[++length] = num % BASE;
            num /= BASE;
        }

        return *this;
    }

    // 赋值运算符（高精度整数）
    BigInteger& operator=(const BigInteger& other) {
        if (this != &other) {
            memcpy(digits, other.digits, sizeof(other.digits));
            length = other.length;
        }
        return *this;
    }

    // 乘法运算符（乘以整数）
    void operator*=(int num) {
        if (num == 0) {
            *this = 0;
            return;
        }

        // 每一位乘以num
        for (int i = 1; i <= length; i++) {
            digits[i] *= num;
        }

        // 处理进位
        for (int i = 1; i <= length; i++) {
            digits[i + 1] += digits[i] / BASE;
            digits[i] %= BASE;
            if (i + 1 > length && digits[i + 1] > 0) {
                length++;
            }
        }

        // 去除前导零
        while (length > 0 && digits[length] == 0) {
            length--;
        }
    }

    // 除法运算符（除以整数）
    BigInteger operator/(int divisor) const {
        if (divisor == 0) {
            throw runtime_error("Division by zero");
        }

        BigInteger result;
        result = *this;

        // 去除前导零
        while (result.length > 0 && result.digits[result.length] == 0) {
            result.length--;
        }

        // 从高位开始除
        for (int i = result.length; i >= 1; i--) {
            // 将余数乘以BASE加到下一位
            if (i > 1) {
                result.digits[i - 1] += (result.digits[i] % divisor) * BASE;
            }
            result.digits[i] /= divisor;
        }

        // 去除前导零
        while (result.length > 0 && result.digits[result.length] == 0) {
            result.length--;
        }

        return result;
    }

    // 大于运算符
    bool operator>(const BigInteger& other) const {
        if (length != other.length) {
            return length > other.length;
        }

        for (int i = length; i >= 1; i--) {
            if (digits[i] != other.digits[i]) {
                return digits[i] > other.digits[i];
            }
        }

        return false; // 相等
    }

    // 输出函数
    void print() const {
        if (length == 0) {
            cout << "0";
            return;
        }

        cout << digits[length]; // 最高位不需要补零

        // 其余位需要补零至4位
        for (int i = length - 1; i >= 1; i--) {
            cout.width(4);
            cout.fill('0');
            cout << digits[i];
        }
    }
};

// 大臣结构体
struct Minister {
    int left;  // 左手上的数
    int right; // 右手上的数

    // 排序运算符
    bool operator<(const Minister& other) const {
        long long product1 = (long long)left * right;
        long long product2 = (long long)other.left * other.right;

        if (product1 != product2) {
            return product1 < product2;
        }

        return left < other.left; // 如果乘积相同，按左手数排序
    }
};

int main() {
    int n;
    cin >> n;

    Minister king;
    cin >> king.left >> king.right;

    Minister ministers[MAXN];
    for (int i = 1; i <= n; i++) {
        cin >> ministers[i].left >> ministers[i].right;
    }

    // 按照left*right的乘积从小到大排序
    sort(ministers + 1, ministers + n + 1);

    // 计算每个大臣获得的金币数
    BigInteger product;
    product = king.left; // 初始为国王的左手数

    BigInteger max_coins;
    max_coins = 0;

    for (int i = 1; i <= n; i++) {
        BigInteger coins = product / ministers[i].right;

        if (coins > max_coins) {
            max_coins = coins;
        }

        product *= ministers[i].left;
    }

    max_coins.print();

    return 0;
}
