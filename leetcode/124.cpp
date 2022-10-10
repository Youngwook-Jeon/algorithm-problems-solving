#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  int ans = INT_MIN;

  int oneSideMax(TreeNode *root)
  {
    if (root == nullptr)
      return 0;
    int leftMax = max(0, oneSideMax(root->left));
    int rightMax = max(0, oneSideMax(root->right));

    ans = max(ans, leftMax + rightMax + root->val);
    return max(leftMax, rightMax) + root->val;
  }

  int maxPathSum(TreeNode *root)
  {
    oneSideMax(root);
    return ans;
  }
};