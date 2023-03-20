#include "leetcode_ds.h"
#include <queue>
using namespace std;

class Solution
{
public:
    TreeLinkedNode *connect(TreeLinkedNode *root)
    {
        if (root == NULL)
            return root;

        queue<TreeLinkedNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeLinkedNode *cur = q.front();
                q.pop();

                if (i < sz - 1)
                {
                    cur->next = q.front();
                }

                if (cur->left != NULL)
                {
                    q.push(cur->left);
                }
                if (cur->right != NULL)
                {
                    q.push(cur->right);
                }
            }
        }

        return root;
    }
};