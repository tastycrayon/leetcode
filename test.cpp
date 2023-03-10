#include <iostream>
using namespace std;

class Solution {
 public:
  int removeStudents(int H[], int N) {
    // {9, 1, 2, 3, 1, 5}
    // {9, 10, 11, 1, 2, 3, 4}
    if (N == 1) return N;
    int minimum = 0;
    int tallOne = 0;
    int ahead = 0;
    for (int i = 1; i < N; i++) {
      int front = H[i - 1];
      int current = H[i];
      if (tallOne == 0) continue;
      if (front > tallOne) tallOne = front;
      if (front < current) continue;
    }

    return minimum;
  }
};
int main(int argc, char const *argv[]) {
  int H[] = {9, 1, 2, 3, 1, 5};
  cout << (Solution().removeStudents(H, 6));
  return 0;
}
