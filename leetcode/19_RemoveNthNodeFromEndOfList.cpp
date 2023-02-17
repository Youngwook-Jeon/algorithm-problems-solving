#include "leetcode_ds.h"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *first = &dummy;
        ListNode *second = &dummy;

        for (int i = 1; i <= n + 1; i++)
        {
            first = first->next;
        }

        while (first != nullptr)
        {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;
        return dummy.next;
    }
};