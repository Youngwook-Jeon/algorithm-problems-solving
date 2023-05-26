#include <vector>
#include "leetcode_ds.h"
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
    vector<vector<int>> ans;

    vector<vector<int>> findLeaves(TreeNode *root)
    {
        ans.clear();
        solve(root);

        return ans;
    }

    int solve(TreeNode *root)
    {
        if (root == nullptr)
            return -1;

        int leftHeight = solve(root->left);
        int rightHeight = solve(root->right);
        int curHeight = max(leftHeight, rightHeight) + 1;

        if (ans.size() == curHeight)
        {
            ans.push_back({});
        }

        ans[curHeight].push_back(root->val);

        return curHeight;
    }
};