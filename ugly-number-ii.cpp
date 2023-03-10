#include <iostream>
#include <vector>
// #include <cmath>
#define log(x) std::cout << x << std ::endl;

class Solution {
 public:
  int nthUglyNumber(int n) {
    if (n <= 0) return false;
    std::vector<int> cache(1, 1);
    cache.reserve(n);
    int i = 0, j = 0, k = 0;
    int p, q, r;

    while (cache.size() < n) {
      p = cache[i] * 2, q = cache[j] * 3, r = cache[k] * 5;
      cache.push_back(std::min(p, std::min(q, r)));
      if (cache.back() == p) i++;
      if (cache.back() == q) j++;
      if (cache.back() == r) k++;
    }
    return cache.back();
  }
};

int main(int argc, char const *argv[]) {
  int num = 10;
  int result = Solution().nthUglyNumber(num);
  std::cout << "Result: " << result << std::endl;
  return 0;
}
