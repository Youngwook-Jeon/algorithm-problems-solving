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
    bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target)
    {
        vector<int> r1;
        vector<int> r2;
        inorder(root1, r1);
        inorder(root2, r2);
        int s = 0, e = r2.size() - 1;

        while (s < r1.size() && e >= 0)
        {
            if (r1[s] + r2[e] == target)
                return true;

            if (r1[s] + r2[e] < target)
                s++;
            else
                e--;
        }

        return false;
    }

    void inorder(TreeNode *root, vector<int> &r)
    {
        if (root == nullptr)
            return;
        inorder(root->left, r);
        r.push_back(root->val);
        inorder(root->right, r);
    }
};