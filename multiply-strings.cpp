#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

// num1 : "123", num2 : "456", "56088",
//   123
//   456
//   738
//  615x
// 492xx
// 56088

class Solution {
 public:
  string multiply(string num1, string num2) {
    const char zero = '0';
    if (num1.length() == 1 && num1[0] == zero) return "0";
    if (num2.length() == 1 && num2[0] == zero) return "0";

    int maxLength = num1.length() + num2.length();

    vector<int8_t> result = vector<int8_t>(maxLength, 0);
    int resultIndex = maxLength - 2;

    for (int i = num2.length() - 1; i >= 0; i--) {
      int digit2 = num2[i] - zero;
      for (int j = num1.length() - 1; j >= 0; j--) {
        int digit1 = num1[j] - zero, carry = 0;
        result[i + j + 1] += digit1 * digit2;
        result[i + j] += result[i + j + 1] / 10;
        result[i + j + 1] %= 10;
      }
    }
    string strResult;
    strResult.reserve(maxLength);
    bool checkForZero = 1;
    for (int i = 0; i < result.size(); i++) {
      if (result[i] != 0) checkForZero = false;
      if (checkForZero) continue;
      strResult.push_back(result[i] + zero);
    }
    return strResult;
  }
};

struct CaseType {
  string num1;
  string num2;
  string result;
};
int main(int argc, char const *argv[]) {
  CaseType cases[] = {
      {
        num1 : "2",
        num2 : "13",
        result : "26",
      },
      {
        num1 : "123",
        num2 : "456",
        result : "56088",
      },
      {
        num1 : "9",
        num2 : "9",
        result : "81",
      },
      {
        num1 : "925101087184894",
        num2 : "3896737933784656127",
        result : "3604876499018802870538090258945538",
      },
  };

  for (int i = 0; i < 4; i++) {
    string result = Solution().multiply(cases->num1, cases->num2);
    cout << (result == cases->result) << endl;
  }

  return 0;
}
