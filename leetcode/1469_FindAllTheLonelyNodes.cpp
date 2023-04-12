#include "leetcode_ds.h"
#include <vector>
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
    vector<int> ans;

    vector<int> getLonelyNodes(TreeNode *root)
    {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;

        auto left = root->left;
        auto right = root->right;
        if (left != nullptr && right == nullptr)
        {
            ans.push_back(left->val);
        }

        if (left == nullptr && right != nullptr)
        {
            ans.push_back(right->val);
        }

        dfs(left);
        dfs(right);
    }
};