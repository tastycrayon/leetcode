#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define log(x) std::cout << x << std ::endl;
using namespace std;

// class Solution {
// public:
//   int hammingWeight(uint32_t  n) {
//     unsigned int result = 0;
//     for (int i = 0; i < 32; i++)
//       if (!!(n & (1 << i))) result++;

//     return result;
//   }
// };
class Solution {
 public:
  int divide(int dividend, int divisor) {
    int quotient = 0, remainder = 0;
    int temp = dividend;
    int counter = 31;
    for (int i = 31; i >= 0; i--) {
      if (dividend & (1 << i)) break;
      counter--;
    }

    for (int i = 0; i < 10; i++) {
    }
    return 1;
  }
};

int main(int argc, char const *argv[]) {
  int d = 10, dv = 3;
  int result = Solution().divide(d, dv);
  cout << result << endl;
  return 0;
}
