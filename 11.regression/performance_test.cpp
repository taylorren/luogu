#include <bits/stdc++.h>
#include <chrono>
#include <climits>
using namespace std;
using namespace std::chrono;

// Original implementation
long long catalan_original(int n) {
    long long h[30] = {1, 1};  // Increased array size to handle up to n=29
    
    for(int i = 2; i <= n; i++) {
        h[i] = 0;  // Initialize to 0
        for(int j = 0; j < i; j++) {
            h[i] += h[j] * h[i-j-1];
        }
    }
    
    return h[n];
}

// Optimized implementation
long long catalan_optimized(int n) {
    if (n <= 1) return 1;

    long long result = 1;
    for (int i = 0; i < n; ++i) {
        // Check for potential overflow before multiplication
        if (result > LLONG_MAX / (2 * n - i)) {
            cout << "Overflow detected at n=" << n << endl;
            return -1; // Indicate overflow
        }
        result = result * (2 * n - i) / (i + 1);
    }
    
    // Check for overflow when dividing by (n+1)
    if (result % (n + 1) != 0 || result / (n + 1) < 0) {
        cout << "Potential overflow or division issue at n=" << n << endl;
        return -1;
    }
    
    return result / (n + 1);
}

int main() {
    const int test_n = 30;  // Test with n=25 for both implementations
    
    // Time the original implementation
    auto start = high_resolution_clock::now();
    long long result_orig = catalan_original(test_n);
    auto end = high_resolution_clock::now();
    auto duration_orig = duration_cast<nanoseconds>(end - start);
    
    // Time the optimized implementation
    start = high_resolution_clock::now();
    long long result_opt = catalan_optimized(test_n);
    end = high_resolution_clock::now();
    auto duration_opt = duration_cast<nanoseconds>(end - start);
    
    cout << "Original implementation result: " << result_orig << endl;
    cout << "Optimized implementation result: " << result_opt << endl;
    cout << "Original implementation time: " << duration_orig.count() << " nanoseconds" << endl;
    cout << "Optimized implementation time: " << duration_opt.count() << " nanoseconds" << endl;
    
    if(result_orig == result_opt) {
        cout << "Both implementations produce the same result." << endl;
    } else {
        cout << "ERROR: Implementations produce different results!" << endl;
    }
    
    // Show the theoretical complexity difference
    cout << "\nThe optimized version has O(n) time complexity versus O(n^2) for the original." << endl;
    cout << "As n increases, the performance difference becomes more significant." << endl;
    
    return 0;
}