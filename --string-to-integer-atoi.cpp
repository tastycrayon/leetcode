#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;
class Solution {
 public:
  int myAtoi(string s) {
    bool leadingWhiteSpaceFlag = true;
    bool isPositive = true;

    return 0;
  }
};

struct CaseType {
  string s;
  int result;
};

int main(int argc, char const *argv[]) {
  CaseType cases[] = {
      {s : "42", result : 42},
      {s : "   -42", result : -42},
      {s : "4193 with words", result : 4193},
  };

  for (int i = 0; i < 4; i++) {
    int result = Solution().myAtoi(cases->s);
    cout << (result == cases->result) << endl;
  }

  return 0;
}
