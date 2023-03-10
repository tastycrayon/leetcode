#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    unsigned int i = 0, j = 0, k = 0;
    unsigned int totalSize = nums1.size() + nums2.size();
    bool odd = totalSize & 1;
    vector<int> mergedArr = vector<int>(totalSize);
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] <= nums2[j])
        mergedArr[k] = nums1[i++];
      else
        mergedArr[k] = nums2[j++];
      k++;
    }
    while (i < nums1.size()) mergedArr[k++] = nums1[i++];
    while (j < nums2.size()) mergedArr[k++] = nums2[j++];

    unsigned int half = totalSize / 2;
    if (odd) return (double)mergedArr[half];

    return (double)(mergedArr[half] + mergedArr[half - 1]) / 2;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> arr1 = {1, 2};
  vector<int> arr2 = {3, 4};
  int n = 6;
  // double result = Solution().findMedianSortedArrays(arr1, arr2);
  double result = Solution().findMedianSortedArrays(arr1, arr2);
  cout << "Result: " << result << endl;
}