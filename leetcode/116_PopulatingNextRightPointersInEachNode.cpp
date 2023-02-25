#include "leetcode_ds.h"

class Solution
{
public:
  TreeLinkedNode *connect(TreeLinkedNode *root)
  {
    if (root == nullptr || root->left == nullptr)
      return root;

    root->left->next = root->right;
    root->right->next = root->next ? root->next->left : nullptr;
    root->left = connect(root->left);
    root->right = connect(root->right);
    return root;
  }
};