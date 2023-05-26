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
    double ans;

    double maximumAverageSubtree(TreeNode *root)
    {
        solve(root);
        return ans;
    }

    pair<int, int> solve(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0};

        auto leftRes = solve(root->left);
        auto rightRes = solve(root->right);
        double avg = (double)(leftRes.first + rightRes.first + root->val) / (leftRes.second + rightRes.second + 1);

        ans = max(ans, avg);

        return {leftRes.first + rightRes.first + root->val, leftRes.second + rightRes.second + 1};
    }
};