#include <iostream>
#include <vector>
#include <cmath>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  int deterMinant(int a, int b, int d, int e, int g, int h) {
    int c = 1, f = 1, i = 1;
    return a * (e * i - f * h) - b * (d * i - g * f) + c * (d * h - e * g);
  }

  int maxPoints(vector<vector<int>>& points) {
    // int x1 = points[1][0], y1 = points[1][1];
    // int x2 = points[2][0], y2 = points[2][1];
    // double delX = abs(x2 - x1);
    // double delY = abs(y2 - y1);
    // double m = delY / delX;
    // double b = y1 - m * x1;
    int i = 0, j = 1, result = 0, pointsSize = points.size();
    if (pointsSize <= 1) return pointsSize;

    for (int i = 0; i < pointsSize; i++) {
      for (int j = 0; j < pointsSize; j++) {
        if (i == j) continue;
        int counter = 2;  // there is already 2 set
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];
        for (int k = 0; k < pointsSize; k++) {
          if (i == k || j == k) continue;  // skip current set
          int x3 = points[k][0], y3 = points[k][1];
          if (deterMinant(x1, y1, x2, y2, x3, y3) == 0) counter++;
        }
        result = max(counter, result);
      }
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> arr = {{1, 1}, {2, 2}, {3, 3}};

  double result = Solution().maxPoints(arr);
  cout << "Result: " << result << endl;
}