#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, k;
    cin >> n >> k;
    
    unordered_set<int> rows, cols;
    rows.reserve(k);
    cols.reserve(k);
    
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        rows.insert(r);
        cols.insert(c);
    }
    
    long long row_count = rows.size();
    long long col_count = cols.size();
    
    long long total = row_count * n + col_count * n - row_count * col_count;
    
    cout << total << endl;
    
    return 0;
}