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

    vector<int> boundaryOfBinaryTree(TreeNode *root)
    {
        ans.push_back(root->val);
        if (!root->left && !root->right)
            return ans;

        findLeftBoundaries(root->left);
        findLeaves(root);
        findRightBoundaries(root->right);

        return ans;
    }

    void findLeftBoundaries(TreeNode *node)
    {
        if (node == nullptr)
            return;
        if (!node->left && !node->right)
        {
            return;
        }

        ans.push_back(node->val);

        if (node->left)
        {
            findLeftBoundaries(node->left);
        }
        else
        {
            findLeftBoundaries(node->right);
        }
    }

    void findRightBoundaries(TreeNode *node)
    {
        if (node == nullptr)
            return;
        if (!node->left && !node->right)
        {
            return;
        }

        if (node->right)
        {
            findRightBoundaries(node->right);
        }
        else
        {
            findRightBoundaries(node->left);
        }
        ans.push_back(node->val);
    }

    void findLeaves(TreeNode *root)
    {
        if (root == nullptr)
            return;
        if (!root->left && !root->right)
        {
            ans.push_back(root->val);
            return;
        }

        findLeaves(root->left);
        findLeaves(root->right);
    }
};