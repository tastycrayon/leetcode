#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;

class Solution {
 public:
  std::vector<int> primes = {3, 5};

  bool isUgly(int n) {
    if (n < 1) return 0;
    while ((n & 1) == 0) n >>= 1;  // for prime = 2
    if (n == 1) return 1;          // if it is a power of 2
    for (int &prime : primes)
      while (n % prime == 0) n /= prime;

    return n == 1;
  }
};
int main(int argc, char const *argv[]) {
  int num = -2147483648;
  bool result = Solution().isUgly(num);
  std::cout << "Result: " << (result ? "True" : "False") << std::endl;
  return 0;
}
