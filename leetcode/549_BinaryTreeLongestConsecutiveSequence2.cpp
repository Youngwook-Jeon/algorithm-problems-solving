#include "leetcode_ds.h"
#include <algorithm>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int ans = 0;

    int longestConsecutive(TreeNode *root)
    {
        solve(root);
        return ans;
    }

    pair<int, int> solve(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0};
        int asc = 1, desc = 1;

        if (root->left != nullptr)
        {
            auto leftRes = solve(root->left);
            if (root->val + 1 == root->left->val)
            {
                asc = leftRes.first + 1;
            }
            else if (root->val - 1 == root->left->val)
            {
                desc = leftRes.second + 1;
            }
        }

        if (root->right != nullptr)
        {
            auto rightRes = solve(root->right);
            if (root->val + 1 == root->right->val)
            {
                asc = max(rightRes.first + 1, asc);
            }
            else if (root->val - 1 == root->right->val)
            {
                desc = max(rightRes.second + 1, desc);
            }
        }

        ans = max(ans, asc + desc - 1);

        return {asc, desc};
    }
};