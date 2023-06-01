#include "leetcode_ds.h"
#include <algorithm>
#include <climits>
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
class TreeProperties
{
public:
    int maxVal, minVal, maxSize;

    TreeProperties(int maxVal, int minVal, int maxSize) : maxVal(maxVal), minVal(minVal), maxSize(maxSize) {}
};

class Solution
{
public:
    int largestBSTSubtree(TreeNode *root)
    {
        return solve(root).maxSize;
    }

    TreeProperties solve(TreeNode *root)
    {
        if (root == nullptr)
            return TreeProperties(INT_MIN, INT_MAX, 0);

        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left.maxVal < root->val && right.minVal > root->val)
        {
            return TreeProperties(
                max(root->val, right.maxVal),
                min(root->val, left.minVal),
                left.maxSize + right.maxSize + 1);
        }

        return TreeProperties(INT_MAX, INT_MIN, max(left.maxSize, right.maxSize));
    }
};