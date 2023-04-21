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
    int rob(TreeNode *root)
    {
        auto p = solve(root);
        return max(p.first, p.second);
    }

    pair<int, int> solve(TreeNode *node)
    {
        if (node == nullptr)
            return {0, 0};

        auto left = solve(node->left);
        auto right = solve(node->right);

        int notRobbed = max(left.first, left.second) + max(right.first, right.second);
        int robbed = node->val + left.first + right.first;

        return {notRobbed, robbed};
    }
};