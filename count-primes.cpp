#include <iostream>
#include <vector>
#include <cmath>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    if (n < 2) return 0;

    unsigned int result = n - 2, sqrtOfn = sqrt(n);

    vector<bool> nonPrimes = vector<bool>(n, 0);
    nonPrimes[0] = nonPrimes[1] = 1;
    for (int i = 2; i <= sqrtOfn; i++) {
      if (nonPrimes[i]) continue;
      int j = i * i;
      while (j < n) {
        if (nonPrimes[j]) {
          j += i;
          continue;
        }
        nonPrimes[j] = 1;
        result--;
      }
      // non faster
      // for (int j = i; i * j < n; j++) {
      //   if (nonPrimes[i * j]) continue;
      //   nonPrimes[i * j] = 1;
      //   result--;
      // }
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  int n = 5e6;
  int result = Solution().countPrimes(n);

  cout << "Result: " << result << endl;

  return 0;
}
// 1 2 3 4 5 6 7 8 9 10