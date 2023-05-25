#include "leetcode_ds.h"

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

    int countUnivalSubtrees(TreeNode *root)
    {
        isUnival(root);
        return ans;
    }

    bool isUnival(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        bool leftRes = isUnival(root->left);
        bool rightRes = isUnival(root->right);

        if (root->left != nullptr && (!leftRes || root->val != root->left->val))
        {
            return false;
        }

        if (root->right != nullptr && (!rightRes || root->val != root->right->val))
        {
            return false;
        }

        ans++;

        return true;
    }
};