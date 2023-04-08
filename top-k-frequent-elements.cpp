#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

struct Element {
  int num;
  int frequency;
};

class Compare {
 public:
  bool operator()(Element below, Element above) {
    return below.frequency > above.frequency;
  }
};

struct CustomPriorityQueue : priority_queue<Element, vector<Element>, Compare> {
  auto begin() const { return c.begin(); }
  auto end() const { return c.end(); }
};

class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> result = {};
    result.reserve(k);
    sort(nums.begin(), nums.end());
    CustomPriorityQueue pq;
    int temp = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++) {
      int currentFreq = 1, current = nums[i];

      while (i < temp && nums[i + 1] == current) {
        currentFreq++;
        i++;
      }
      if (pq.size() < k) {
        pq.push({current, currentFreq});
        continue;
      }

      if (pq.top().frequency > currentFreq) continue;
      // current item has higher frequency, so replace it.
      pq.pop();
      pq.push({current, currentFreq});
    }

    for (Element e : pq) result.push_back(e.num);

    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution leet;
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  vector<int> result = leet.topKFrequent(nums, 2);

  cout << "Result: ";
  for (int i = 0; i < (int)result.size(); i++) cout << result[i] << ' ';
  cout << endl;
  return 0;
}