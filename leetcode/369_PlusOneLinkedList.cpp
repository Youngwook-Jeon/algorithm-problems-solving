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
    ListNode *plusOne(ListNode *head)
    {
        ListNode *guard = new ListNode(0);
        guard->next = head;
        ListNode *notNine = guard;

        while (head != nullptr)
        {
            if (head->val != 9)
                notNine = head;
            head = head->next;
        }

        notNine->val += 1;
        ListNode *nine = notNine->next;
        while (nine != nullptr)
        {
            nine->val = 0;
            nine = nine->next;
        }

        if (guard->val != 0)
            return guard;
        head = guard->next;
        delete guard;
        return head;
    }
};