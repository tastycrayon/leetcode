#include <algorithm>
#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    const int NUM_OF_ITEMS = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int i = 0; i < NUM_OF_ITEMS - 2; i++) {
      int num1 = nums[i];
      int j = i + 1, k = NUM_OF_ITEMS - 1;
      while (j < k) {
        int num2 = nums[j], num3 = nums[k];
        int threeSum = num2 + num3 + num1;
        if (threeSum < 0) {
          j++;
          continue;
        }
        if (threeSum > 0) {
          k--;
          continue;
        }

        result.push_back(vector<int>{num1, num2, num3});
        do {
          j++;
        } while (j < k && nums[j - 1] == nums[j]);  // avoid repeat
        do {
          k--;
        } while (j < k && nums[k + 1] == nums[k]);  // avoid repeat
      }
      // avoid repeat
      while (i < NUM_OF_ITEMS - 1 && nums[i] == nums[i + 1]) i++;
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  // vector<int> nums = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = Solution().threeSum(nums);

  cout << "Result: " << endl;
  for (vector<int> r : result) {
    for (auto&& item : r) cout << item << ' ';
    cout << endl;
  }
  // {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4}
  //[[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]
  // expected
  return 0;
}
