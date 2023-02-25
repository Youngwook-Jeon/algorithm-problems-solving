struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TreeLinkedNode
{
public:
  int val;
  TreeLinkedNode *left;
  TreeLinkedNode *right;
  TreeLinkedNode *next;

  TreeLinkedNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  TreeLinkedNode(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  TreeLinkedNode(int _val, TreeLinkedNode *_left, TreeLinkedNode *_right, TreeLinkedNode *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};