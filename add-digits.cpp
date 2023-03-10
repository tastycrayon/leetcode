#include <iostream>
#define log(x) std::cout << x << std ::endl;

class Solution {
 public:
  int addDigits(int num) {
    if (num == 0) return 0;
    if (num % 9 == 0) return 9;
    return num % 9;
  }
};
// class Solution {
//
//  public:
//   int addDigits(int num) {
//     int divider = 10;
//     int sum = 0;
//     while (num) {
//       while (num) {
//         sum += num % divider;
//         num /= divider;
//       }
//       if (sum < 10) break;
//       num = sum;
//       sum = 0;
//     }
//     return sum;
//   }
// };

int main(int argc, char const *argv[]) {
  int num = 38;
  int result = Solution().addDigits(num);
  std::cout << "Result: " << result << std::endl;
  return 0;
}
