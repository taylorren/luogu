#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
  if (num <= 1)
    return false;
  if (num == 2)
    return true;
  if (num % 2 == 0)
    return false;
  for (int i = 3; i <= sqrt(num); i += 2) {
    if (num % i == 0)
      return false;
  }
  return true;
}

// Function to count the number of 1s in the binary representation of a number
int countOnes(int num) {
  int count = 0;
  while (num) {
    num &= (num - 1);
    count++;
  }
  return count;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int count = 0;
  int total_combinations = 1 << n; // 2^n combinations

  for (int mask = 0; mask < total_combinations; mask++) {
    if (countOnes(mask) == k) // 有k个1，表示取了k个数字
    {
      int sum = 0;
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          sum += nums[i];
        }
      }
      if (isPrime(sum)) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}