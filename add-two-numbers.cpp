#include <iostream>
#include <vector>
#include <cmath>
#define log(x) std::cout << x << std ::endl;
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 243
// 564
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *headPtr = new ListNode();
    ListNode *current = headPtr;
    int sum = 0;
    while (l1 != nullptr || l2 != nullptr) {
      sum += (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val);
      current->next = new ListNode(sum % 10);
      sum /= 10;

      current = current->next;
      l1 = l1 == nullptr ? nullptr : l1->next;
      l2 = l2 == nullptr ? nullptr : l2->next;
    }

    if (sum) current->next = new ListNode(1);

    return headPtr->next;
  }
};

int main(int argc, char const *argv[]) {
  ListNode *head1 = new ListNode(2);
  head1->next = new ListNode(4);
  head1->next->next = new ListNode(3);

  ListNode *head2 = new ListNode(5);
  head2->next = new ListNode(6);
  head2->next->next = new ListNode(6);
  head2->next->next->next = new ListNode(4);

  ListNode *result = Solution().addTwoNumbers(head1, head2);

  ListNode *temp = result;
  while (temp != nullptr) {
    cout << temp->val << ' ';
    temp = temp->next;
  }

  return 0;
}
// 1 2 3 4 5 6 7 8 9 10