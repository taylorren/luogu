#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  deque<int> dq; // 双端队列存储索引
  vector<int> result;

  for (int i = 0; i < n; ++i) {
    // 移除不在窗口范围内的元素
    if (!dq.empty() && dq.front() < i - k + 1) {
      dq.pop_front();
    }

    // 移除队列中比当前元素小的元素（保持递减顺序）
    while (!dq.empty() && nums[dq.back()] <= nums[i]) {
      dq.pop_back();
    }

    // 将当前元素加入队列
    dq.push_back(i);

    // 当窗口大小达到 k 时，记录当前窗口的最大值
    if (i >= k - 1) {
      result.push_back(nums[dq.front()]);
    }
  }

  // 输出结果
  for (int max_val : result) {
    cout << max_val << endl;
  }

  return 0;
}