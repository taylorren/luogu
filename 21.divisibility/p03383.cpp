#include <bits/stdc++.h> // 包含了常用的头文件

using namespace std; // 使用 std 命名空间

// 全局变量，以应对较大的 n 值 (最大 10^8)
// MAX_N_RANGE 定义了is_composite数组的最大索引，即我们筛选素数的上限
const int MAX_N_RANGE = 100000000;
vector<bool> is_composite(MAX_N_RANGE + 1,
                               false);  // is_composite[i] = true 表示 i 是合数
vector<int> primes_list;           // 存储找到的素数

// 线性筛函数
void linear_sieve(int limit)
{
    is_composite[0] = is_composite[1] = true;  // 0 和 1 不是素数

    for (int i = 2; i <= limit; ++i)
    {
        if (!is_composite[i])
        {  // 如果 i 不是合数，那么它是素数
            primes_list.push_back(i);
        }
        // 对于每个数 i，用已找到的素数 primes_list[j] 去标记 i * primes_list[j]
        // (long long) 用于防止 i * primes_list[j] 在比较前溢出，尽管在此题 n <=
        // 10^8 下，int 通常足够
        for (int j = 0;
             j < primes_list.size() && (long long)i * primes_list[j] <= limit;
             ++j)
        {
            is_composite[i * primes_list[j]] = true;  // 标记为合数
            if (i % primes_list[j] == 0)
            {
                // 如果 i 是 primes_list[j] 的倍数,
                // 说明 primes_list[j] 是 i 的最小质因子。
                // 任何 i * primes_list[k] (k > j) 的最小质因子也会是
                // primes_list[j]。 为了保证每个合数只被其最小质因子筛一次，这里
                // break。
                break;
            }
        }
    }
}

int main()
{
    // 加速 C++ I/O
    ios::sync_with_stdio(0); // 由于 using namespace std; std:: 可以省略
    cin.tie(0);
    cout.tie(0);

    int n_query_range, q_num_queries;
    cin >> n_query_range >> q_num_queries;

    // 执行线性筛，找出所有 <= n_query_range 的素数
    linear_sieve(n_query_range);

    // 处理 q_num_queries 个查询
    for (int i = 0; i < q_num_queries; ++i)
    {
        int k;
        cin >> k;
        // 输出第 k 小的素数 (primes_list 是 0-indexed)
        cout << primes_list[k - 1] << '\n';
    }

    return 0;
}