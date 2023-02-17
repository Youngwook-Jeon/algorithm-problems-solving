#include "leetcode_ds.h"

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int sz = 0;
        ListNode *now = head;
        while (now != nullptr)
        {
            sz++;
            now = now->next;
        }

        int target = sz / 2 + 1;
        int cur = 1;
        ListNode *ret = head;
        while (cur != target)
        {
            ret = ret->next;
            cur++;
        }

        return ret;
    }
};