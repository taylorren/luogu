#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<int> s;
    int num;

    // 读取输入
    while (cin >> num) {
        s.push_back(num);
    }

    int n = s.size();
    long long sum_of_elements = 0;

    // 计算元素的和
    for (int i = 0; i < n; ++i) {
        sum_of_elements += s[i];
    }

    // 计算所有子集元素之和
    long long total_sum = (1LL << (n - 1)) * sum_of_elements;

    // 输出结果
    cout << total_sum << std::endl;

    return 0;
}