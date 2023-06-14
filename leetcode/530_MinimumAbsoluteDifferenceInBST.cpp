#include "leetcode_ds.h"
#include <vector>
#include <climits>
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
    int ans = INT_MAX;
    vector<int> arr;

    int getMinimumDifference(TreeNode *root)
    {
        inorder(root);
        for (int i = 1; i < arr.size(); i++)
        {
            ans = min(ans, abs(arr[i] - arr[i - 1]));
        }
        return ans;
    }

    void inorder(TreeNode *node)
    {
        if (node == nullptr)
            return;

        inorder(node->left);
        arr.push_back(node->val);
        inorder(node->right);
    }
};