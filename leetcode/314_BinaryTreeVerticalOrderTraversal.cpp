#include "leetcode_ds.h"
#include <unordered_map>
#include <queue>
#include <vector>
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
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        unordered_map<int, vector<int>> table;
        queue<pair<TreeNode *, int>> q;
        int col = 0;
        int minCol = 0, maxCol = 0;
        q.push({root, col});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int curCol = p.second;

            table[curCol].push_back(node->val);
            minCol = min(minCol, curCol);
            maxCol = max(maxCol, curCol);

            if (node->left)
            {
                q.push({node->left, curCol - 1});
            }

            if (node->right)
            {
                q.push({node->right, curCol + 1});
            }
        }

        for (int i = minCol; i <= maxCol; i++)
        {
            ans.push_back(table[i]);
        }

        return ans;
    }
};