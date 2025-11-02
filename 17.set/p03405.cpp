#include <bits/stdc++.h>
using namespace std;

struct City {
    string name;
    string state;
};

int main() {
    int n;
    cin >> n;
    
    unordered_map<string, vector<City>> cityMap;
    
    // 读入所有城市信息
    for (int i = 0; i < n; i++) {
        string name, state;
        cin >> name >> state;
        string prefix = name.substr(0, 2);
        cityMap[prefix].push_back({name, state});
    }
    
    // 统计特殊城市对
    int count = 0;
    
    // 遍历哈希表中的每个城市
    for (const auto& entry : cityMap) {
        // 对于每个前缀对应的城市列表
        for (const City& city1 : entry.second) {  
            // 在哈希表中查找以当前城市state为前缀的城市
            auto it = cityMap.find(city1.state);
            if (it != cityMap.end()) {
                // 遍历所有匹配的城市
                for (const City& city2 : it->second) {
                    // 检查第二个城市的state是否匹配第一个城市的前缀
                    // 并确保两个城市来自不同的州
                    if (city2.state == entry.first && 
                        city1.state != city2.state) {
                        count++;
                    }
                }
            }
        }
    }
    
    cout << count / 2 << endl;
    
    return 0;
}