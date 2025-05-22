#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, z;
};

// 按照z坐标（高度）排序
bool compareByHeight(const Point &a, const Point &b) {
    return a.z < b.z;
}

// 计算两点之间的欧几里得距离
double distance(const Point &a, const Point &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    
    // 读取所有点的坐标
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }
    
    // 按照高度排序
    sort(points.begin(), points.end(), compareByHeight);
    
    // 计算总距离
    double totalDistance = 0.0;
    for (int i = 1; i < n; i++) {
        totalDistance += distance(points[i-1], points[i]);
    }
    
    // 输出结果，保留三位小数
    cout << fixed << setprecision(3) << totalDistance << endl;
    
    return 0;
}