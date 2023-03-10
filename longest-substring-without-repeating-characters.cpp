#include <iostream>
#include <vector>
#include <cmath>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  void printDetail(int left, int right, string &s) {
    cout << s << ' ' << (right - left + 1) << endl;
    for (int i = 0; i < left - 1; i++) cout << '-';
    cout << "↑";
    for (int i = 0; i < right - left - 1; i++) cout << '-';
    if (right != left) cout << "↑";
    cout << endl;
  }
  // abcaabbb
  //   int lengthOfLongestSubstring(string &s) {
  //     if (s.length() <= 1) return s.length();

  //     bool visited[256] = {0};
  //     unsigned int right = 0, left = 0, maxLength = 0;

  //     while (right < s.length()) {
  //       char rightChar = s[right];
  //       char leftChar = s[left];
  //       while (visited[rightChar]) {
  //         visited[leftChar] = 0;
  //         left++;
  //         leftChar = s[left];
  //       }
  //       printDetail(left, right, s);
  //       maxLength = max(maxLength, (right - left + 1));
  //       visited[rightChar] = 1;
  //       right++;
  //     }

  //     return maxLength;
  //   }
  // };
  int lengthOfLongestSubstring(string &s) {
    if (s.length() <= 1) return s.length();

    bool visited[256] = {0};
    unsigned int visitedIndex[256] = {0};
    unsigned int right = 0, left = 0, maxLength = 0;

    while (right < s.length()) {
      char rightChar = s[right];
      char leftChar = s[left];
      if (visited[rightChar]) {
        left = max(visitedIndex[(int)rightChar] + 1, left);
        leftChar = s[left];
      }
      printDetail(left, right, s);
      maxLength = max(maxLength, (right - left + 1));
      visited[rightChar] = 1;
      visitedIndex[rightChar] = right;
      right++;
    }

    return maxLength;
  }
};

int main(int argc, char const *argv[]) {
  Solution leet;
  // string s = "abcaabbb";
  string s = "pwwkew";
  int result = leet.lengthOfLongestSubstring(s);
  cout << "Result: " << result << endl;

  return 0;
}
