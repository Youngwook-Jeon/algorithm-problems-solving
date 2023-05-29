#include "leetcode_ds.h"
#include <queue>
#include <cmath>
#include <climits>
#include <limits>
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
    bool absoluteToleranceCompare(double x, double y)
    {
        return fabs(x - y) <= numeric_limits<double>::epsilon();
    }

    int closestValue(TreeNode *root, double target)
    {
        int curVal = INT_MAX;
        double curDist = 2100000000;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            double dist = fabs(target - node->val);
            if (dist < curDist)
            {
                curVal = node->val;
                curDist = dist;
            }
            else if (absoluteToleranceCompare(dist, curDist))
                curVal = min(curVal, node->val);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        return curVal;
    }
};