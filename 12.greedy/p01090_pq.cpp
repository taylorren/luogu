#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    // 读取所有果子的重量
    vector<int> fruits(n);
    for(int i = 0; i < n; i++) {
        cin >> fruits[i];
    }
    
    // 使用优先队列（小根堆）实现贪心算法
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        pq.push(fruits[i]);
    }
    
    int sum = 0;
    // 每次取出最小的两个元素合并
    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int cost = a + b;
        sum += cost;
        pq.push(cost);
    }
    
    cout << sum << endl;
    return 0;
}