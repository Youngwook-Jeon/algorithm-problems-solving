#include "leetcode_ds.h";

class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    if (list1 == nullptr || list2 == nullptr)
    {
      return (list1 == nullptr) ? list2 : list1;
    }

    int val1 = list1->val, val2 = list2->val;
    if (val1 <= val2)
    {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    }
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
  }
};