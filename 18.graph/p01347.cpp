#include <bits/stdc++.h>
using namespace std;

// 结构体用于存储 Kahn 算法的结果
struct Result {
    bool inconsistency; // 是否存在不一致（环）
    bool unique;        // 是否存在唯一的排序
    string order;       // 排序结果（如果唯一）
};

// 执行 Kahn 算法以确定当前关系图的状态
Result perform_kahn(int n, const vector<vector<int>> &adj, const vector<int> &in_degree) {
    vector<int> temp_in_degree = in_degree;
    queue<int> q;
    
    // 初始化队列，将入度为 0 的节点加入队列
    for(int i = 0; i < n; ++i){
        if(temp_in_degree[i] == 0){
            q.push(i);
        }
    }
    
    string order = "";
    bool unique = true;
    
    while(!q.empty()){
        if(q.size() > 1){
            unique = false; // 如果有多个节点入度为 0，则排序不唯一
        }
        
        int current = q.front();
        q.pop();
        order += char('A' + current);
        
        for(auto &neighbor : adj[current]){
            temp_in_degree[neighbor]--;
            if(temp_in_degree[neighbor] == 0){
                q.push(neighbor);
            }
        }
    }
    
    Result res;
    if(order.size() != n){
        // 存在环，不一致
        res.inconsistency = true;
        res.unique = false;
        res.order = "";
    }
    else{
        res.inconsistency = false;
        if(unique){
            // 存在唯一的排序顺序
            res.unique = true;
            res.order = order;
        }
        else{
            // 排序不唯一
            res.unique = false;
            res.order = "";
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    
    // 读取一个测试用例
    if(!(cin >> n >> m)){
        // 如果没有输入，直接结束
        return 0;
    }
    
    // 初始化邻接表和入度数组
    vector<vector<int>> adj(n, vector<int>());
    vector<int> in_degree(n, 0);
    
    // 用于跟踪是否已存在某条边，避免重复添加
    vector< vector<bool> > edge_exists(n, vector<bool>(n, false));
    
    // 读取所有关系
    vector<string> relations(m);
    for(int i = 0; i < m; ++i){
        cin >> relations[i];
    }
    
    bool determined = false;
    bool inconsistent = false;
    string result = "";
    
    for(int idx = 0; idx < m; ++idx){
        string rel = relations[idx];
        // 解析关系 "A<B"
        if(rel.size() != 3 || rel[1] != '<'){
            // 无效的关系格式，忽略或者根据需要处理
            continue;
        }
        int a = rel[0] - 'A';
        int b = rel[2] - 'A';
        
        // 添加边 a -> b，如果尚未添加
        if(!edge_exists[a][b]){
            adj[a].push_back(b);
            in_degree[b]++;
            edge_exists[a][b] = true;
        }
        
        // 执行 Kahn 算法以检查当前状态
        Result res = perform_kahn(n, adj, in_degree);
        
        if(res.inconsistency){
            result = "Inconsistency found after " + to_string(idx + 1) + " relations.";
            inconsistent = true;
            break;
        }
        if(res.unique && !determined){
            result = "Sorted sequence determined after " + to_string(idx + 1) + " relations: " + res.order + ".";
            determined = true;
            break;
        }
        // 否则，继续处理下一个关系
    }
    
    if(!determined && !inconsistent){
        result = "Sorted sequence cannot be determined.";
    }
    
    cout << result << "\n";
    
    return 0;
}