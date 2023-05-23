#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val)
    {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};

class Solution
{
public:
    Node *insert(Node *head, int insertVal)
    {
        if (head == NULL)
        {
            Node *n = new Node(insertVal);
            n->next = n;
            return n;
        }

        vector<int> vals;
        Node *cur = head;
        while (true)
        {
            vals.push_back(cur->val);
            cur = cur->next;
            if (cur == head)
                break;
        }
        sort(vals.begin(), vals.end());

        vals.push_back(insertVal);
        int i = vals.size() - 1;
        while (i > 0 && vals[i] < vals[i - 1])
        {
            swap(vals[i], vals[i - 1]);
            i--;
        }

        int prev = (i - 1 + vals.size()) % vals.size();
        int next = (i + 1) % vals.size();
        cur = head;
        Node *newNode = new Node(insertVal);
        while (true)
        {
            if (cur->val == vals[prev] && cur->next->val == vals[next])
            {
                newNode->next = cur->next;
                cur->next = newNode;
                break;
            }
            cur = cur->next;
        }

        return head;
    }
};