#include "leetcode_ds.h"
#include <cmath>
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
    vector<int> arr;
    double t;

    vector<int> closestKValues(TreeNode *root, double target, int k)
    {
        t = target;
        inorder(root);
        quickselect(0, arr.size() - 1, k);
        vector<int> ans(k);
        copy(arr.begin(), arr.begin() + k, ans.begin());

        return ans;
    }

    void quickselect(int s, int e, int k)
    {
        if (s >= e)
            return;

        int pivotInd = s + rand() % (e - s + 1);
        pivotInd = partition(s, e, pivotInd);

        if (pivotInd == k)
            return;
        else if (pivotInd < k)
            quickselect(pivotInd + 1, e, k);
        else
            quickselect(s, pivotInd - 1, k);
    }

    int partition(int s, int e, int pivotInd)
    {
        double val = fabs(arr[pivotInd] - t);
        swap(arr[e], arr[pivotInd]);
        int ind = s;
        for (int i = s; i <= e; i++)
        {
            if (fabs(arr[i] - t) < val)
            {
                swap(arr[i], arr[ind]);
                ind++;
            }
        }
        swap(arr[e], arr[ind]);
        return ind;
    }

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
};