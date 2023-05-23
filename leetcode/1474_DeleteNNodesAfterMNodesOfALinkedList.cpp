#include "leetcode_ds.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteNodes(ListNode *head, int m, int n)
    {
        ListNode *cur = head;
        ListNode *last = head;
        while (cur != nullptr)
        {
            int i = m, j = n;
            while (cur != nullptr && i != 0)
            {
                last = cur;
                cur = cur->next;
                i--;
            }

            while (cur != nullptr && j != 0)
            {
                cur = cur->next;
                j--;
            }

            last->next = cur;
        }

        return head;
    }
};