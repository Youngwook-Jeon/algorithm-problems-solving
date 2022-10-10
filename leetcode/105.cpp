#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  unordered_map<int, int> mp;

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      mp[inorder[i]] = i;
    }
    TreeNode* root = solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    return root;
  }

  TreeNode* solve(vector<int>& preorder, int preSt, int preEd, vector<int>& inorder, int inSt, int inEd) {
    if (preSt > preEd || inSt > inEd) return NULL;
    TreeNode* now = new TreeNode(preorder[preSt]);
    int inNow = mp[now->val];
    int numsLeft = inNow - inSt;

    now->left = solve(preorder, preSt + 1, preSt + numsLeft, inorder, inSt, inNow - 1);
    now->right = solve(preorder, preSt + numsLeft + 1, preEd, inorder, inNow + 1, inEd);
    return now;
  }
};