#include "leetcode_ds.h"
using namespace std;

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
    // Solution1: Three paths
    ListNode *swapNodesV1(ListNode *head, int k)
    {
        int n = 0;
        ListNode *ptr = head;
        while (ptr != nullptr)
        {
            n++;
            ptr = ptr->next;
        }

        ListNode *n1 = head;
        ListNode *n2 = head;
        int num = 1;
        int target1 = 0, target2 = 0;

        if (n / 2 >= k)
        {
            target1 = k,
            target2 = n - 2 * k + 1;
        }
        else
        {
            target1 = n - k + 1;
            target2 = 2 * k - n - 1;
        }

        while (num != target1)
        {
            num++;
            n1 = n1->next;
        }
        n2 = n1;
        num = 0;

        while (num != target2)
        {
            num++;
            n2 = n2->next;
        }

        int temp = n1->val;
        n1->val = n2->val;
        n2->val = temp;

        return head;
    }

    // Solution2: Single path
    ListNode *swapNodesV2(ListNode *head, int k)
    {
        int cnt = 0;
        ListNode *target1 = head;
        ListNode *target2 = head;
        ListNode *cur = head;

        while (cur != nullptr)
        {
            cnt++;
            if (target2 != nullptr)
            {
                target2 = target2->next;
            }

            if (cnt == k)
            {
                target1 = cur;
                target2 = head;
            }

            cur = cur->next;
        }

        int temp = target1->val;
        target1->val = target2->val;
        target2->val = temp;

        return head;
    }
};