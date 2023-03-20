#include "leetcode_ds.h"

class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
            return false;

        if (isSame(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSame(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
            return true;
        else if (root == nullptr || subRoot == nullptr)
            return false;

        return root->val == subRoot->val && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
};