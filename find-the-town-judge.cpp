#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {
    if (n == 1) return 1;
    vector<int> set = vector<int>(n + 1, 0);
    int condition = n - 1;
    int result = -1;
    for (int i = 0; i < trust.size(); i++) {
      int first = trust[i][0];
      int second = trust[i][1];
      set[first]--, set[second]++;
      if (set[second] == condition) result = second;
    }
    if (result < 0 || set[result] == condition) return result;
    return -1;
  }
};
// class Solution {
// public:
//   int findJudge(int n, vector<vector<int>> &trust) {
//     vector<int> set = vector<int>(n + 1, 0);
//     for (int i = 0; i < trust.size(); i++) {
//       set[trust[i][0]]--, set[trust[i][1]]++;
//     }
//     for (int i = 1; i < n + 1; i++)
//       if (set[i] == n - 1) return i;

//     return -1;
//   }
// };
int main(int argc, char const *argv[]) {
  vector<vector<int>> trust{{1, 2}, {2, 3}};
  int n = 3;
  int result = Solution().findJudge(n, trust);

  cout << "Result: " << result << endl;

  return 0;
}
// 1 2 3 4 5 6 7 8 9 10