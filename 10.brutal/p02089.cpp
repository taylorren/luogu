#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 如果目标美味程度小于10或大于30，无解
    if (n < 10 || n > 30) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<vector<int>> solutions;
    
    // 10重循环，暴力枚举所有可能的配料组合
    for (int a = 1; a <= 3; a++) {
        for (int b = 1; b <= 3; b++) {
            for (int c = 1; c <= 3; c++) {
                for (int d = 1; d <= 3; d++) {
                    for (int e = 1; e <= 3; e++) {
                        for (int f = 1; f <= 3; f++) {
                            for (int g = 1; g <= 3; g++) {
                                for (int h = 1; h <= 3; h++) {
                                    for (int i = 1; i <= 3; i++) {
                                        for (int j = 1; j <= 3; j++) {
                                            // 计算总和
                                            int sum = a + b + c + d + e + f + g + h + i + j;
                                            
                                            // 如果总和等于目标美味程度
                                            if (sum == n) {
                                                vector<int> solution = {a, b, c, d, e, f, g, h, i, j};
                                                solutions.push_back(solution);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    // 输出结果
    cout << solutions.size() << endl;
    
    // 输出所有方案
    for (const auto& solution : solutions) {
        for (int i = 0; i < 10; i++) {
            cout << solution[i];
            if (i < 9) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}