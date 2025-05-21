#include <bits/stdc++.h>
using namespace std;

struct Triangle {
    long long x;
    long long y;
    long long m;
    int id; // Unique identifier for handling duplicates
};

bool cmp_add(const Triangle &a, const Triangle &b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.m < b.m;
}

bool cmp_remove(const Triangle &a, const Triangle &b) {
    long long a_end = a.x + a.m;
    long long b_end = b.x + b.m;
    if(a_end != b_end) return a_end < b_end;
    if(a.y != b.y) return a.y < b.y;
    return a.m < b.m;
}

struct Interval {
    double start;
    double end;
};

// Function to compute the total union height at a given x
double compute_union_height(const vector<Triangle> &active, double x) {
    vector<Interval> intervals;
    for(auto &t: active){
        double y_start = static_cast<double>(t.y);
        double y_end = static_cast<double>(t.y + t.m - (x - t.x));
        // 确保 y_end >= y_start
        if(y_end < y_start) y_end = y_start;
        intervals.emplace_back(Interval{y_start, y_end});
    }
    if(intervals.empty()) return 0.0;
    // 按照 y_start 排序
    sort(intervals.begin(), intervals.end(), [&](const Interval &a, const Interval &b) -> bool {
        return a.start < b.start;
    });
    // 合并重叠区间并计算总长度
    double total = 0.0;
    double current_low = intervals[0].start;
    double current_high = intervals[0].end;
    for(int i = 1; i < intervals.size(); ++i){
        if(intervals[i].start > current_high){
            total += current_high - current_low;
            current_low = intervals[i].start;
            current_high = intervals[i].end;
        }
        else{
            current_high = max(current_high, intervals[i].end);
        }
    }
    total += current_high - current_low;
    return total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Triangle> triangles(n);
    vector<long long> xs_all;
    for(int i = 0; i < n; i++){
        cin >> triangles[i].x >> triangles[i].y >> triangles[i].m;
        triangles[i].id = i; // 分配唯一ID
        xs_all.push_back(triangles[i].x);
        xs_all.push_back(triangles[i].x + triangles[i].m);
    }
    // 排序并去重所有x坐标
    sort(xs_all.begin(), xs_all.end());
    xs_all.erase(unique(xs_all.begin(), xs_all.end()), xs_all.end());
    vector<long long> sorted_x = xs_all;
    // 按x排序用于添加事件
    vector<Triangle> sorted_add = triangles;
    sort(sorted_add.begin(), sorted_add.end(), cmp_add);
    // 按x + m排序用于移除事件
    vector<Triangle> sorted_remove = triangles;
    sort(sorted_remove.begin(), sorted_remove.end(), cmp_remove);
    int add_idx = 0, remove_idx = 0;
    vector<Triangle> active;
    double area = 0.0;
    int K = sorted_x.size();
    for(int k = 0; k < K-1; k++){
        long long xk = sorted_x[k];
        long long xk1 = sorted_x[k+1];
        double delta_x = static_cast<double>(xk1 - xk);
        // 首先移除在xk结束的三角形
        while(remove_idx < n && (sorted_remove[remove_idx].x + sorted_remove[remove_idx].m) == xk){
            // 使用唯一ID移除对应的三角形
            auto it = find_if(active.begin(), active.end(), [&](const Triangle &t) -> bool {
                return (t.x == sorted_remove[remove_idx].x) &&
                       (t.y == sorted_remove[remove_idx].y) &&
                       (t.m == sorted_remove[remove_idx].m) &&
                       (t.id == sorted_remove[remove_idx].id);
            });
            if(it != active.end()){
                active.erase(it);
            }
            remove_idx++;
        }
        // 然后添加在xk开始的三角形
        while(add_idx < n && sorted_add[add_idx].x == xk){
            active.push_back(sorted_add[add_idx]);
            add_idx++;
        }
        // 计算当前和下一个x位置的覆盖高度
        double h_k = compute_union_height(active, static_cast<double>(xk));
        double h_k1 = compute_union_height(active, static_cast<double>(xk1));
        // 使用梯形公式累加面积
        area += (h_k + h_k1) / 2.0 * delta_x;
    }
    // 输出保留一位小数
    cout << fixed << setprecision(1) << area;
}
