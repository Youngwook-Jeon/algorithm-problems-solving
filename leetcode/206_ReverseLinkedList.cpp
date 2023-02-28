#include "leetcode_ds.h"

class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode *node = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return node;
  }
};