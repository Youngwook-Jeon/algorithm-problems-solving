#include <vector>
#include "leetcode_ds.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> ans;
    TreeNode *T;
    int K;

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        T = target;
        K = k;
        dfs(root);

        return ans;
    }

    // Return the vertex distance from a given node to target node if exists, else -1
    int dfs(TreeNode *node)
    {
        if (node == NULL)
            return -1;
        else if (node == T)
        {
            solve(node, 0);
            return 1;
        }
        else
        {
            int left = dfs(node->left);
            int right = dfs(node->right);

            if (left != -1)
            {
                if (left == K)
                    ans.push_back(node->val);
                solve(node->right, left + 1);
                return left + 1;
            }
            else if (right != -1)
            {
                if (right == K)
                    ans.push_back(node->val);
                solve(node->left, right + 1);
                return right + 1;
            }

            return -1;
        }
    }

    // Find all nodes of which its distance is (K - dist).
    void solve(TreeNode *node, int dist)
    {
        if (node == NULL)
            return;
        if (dist == K)
            ans.push_back(node->val);
        else
        {
            solve(node->left, dist + 1);
            solve(node->right, dist + 1);
        }
    }
};