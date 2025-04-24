#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_map<string, vector<int>> wordMap;
    
    // 读取每篇短文并建立索引
    for (int i = 1; i <= N; ++i) {
        int L;
        cin >> L;
        for (int j = 0; j < L; ++j) {
            string word;
            cin >> word;
            // 只添加第一次出现的短文序号
            if (wordMap[word].empty() || wordMap[word].back() != i) {
                wordMap[word].push_back(i);
            }
        }
    }
    
    int M;
    cin >> M;
    while (M--) {
        string query;
        cin >> query;
        if (wordMap.count(query)) {
            const auto& articles = wordMap[query];
            for (size_t i = 0; i < articles.size(); ++i) {
                if (i) cout << " ";
                cout << articles[i];
            }
        }
        cout << endl;
    }
    
    return 0;
}