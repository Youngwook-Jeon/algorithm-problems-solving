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

    int solve(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftRes = solve(root->left) + 1;
        int rightRes = solve(root->right) + 1;
        if (root->left != nullptr && root->val + 1 != root->left->val)
        {
            leftRes = 1;
        }

        if (root->right != nullptr && root->val + 1 != root->right->val)
        {
            rightRes = 1;
        }

        int localRes = max(leftRes, rightRes);
        ans = max(localRes, ans);

        return localRes;
    }
};