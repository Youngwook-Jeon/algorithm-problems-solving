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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *prev = new ListNode(-1, head);
        while (cur != nullptr)
        {
            if (cur->next == nullptr)
                break;
            ListNode *nextNode = cur->next;
            ListNode *nextCur = nextNode->next;
            cur->next = nextCur;
            nextNode->next = cur;
            prev->next = nextNode;
            if (prev->val == -1)
            {
                head = nextNode;
            }

            cur = nextCur;
            prev = prev->next->next;
        }

        return head;
    }
};