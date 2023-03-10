#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      int otherPart = target - nums[i];
      if (map.find(otherPart) != map.end()) {
        return {map[otherPart], i};
      }
      map[nums[i]] = i;
    }
    return {};
  }
};
// class Solution {
//  public:
//   vector<int> twoSum(vector<int>& nums, int target) {
//     for (int i = 0; i < (int)nums.size(); i++) {
//       int selected = nums[i];
//       for (int j = 0; j < (int)nums.size(); j++) {
//         if (i == j) continue;
//         int current = nums[j];
//         if (selected + current == target) return {i, j};
//       }
//     }
//     return {};
//   }
// };

int main(int argc, char const *argv[]) {
  Solution leet;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> result = leet.twoSum(nums, target);

  for (int i = 0; i < (int)result.size(); i++)
    cout << result[i] << ' ';
  cout << endl;
  return 0;
}
