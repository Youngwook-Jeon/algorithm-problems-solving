#include <vector>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    Node *cloneTree(Node *root)
    {
        if (root == nullptr)
            return root;

        Node *copied = new Node(root->val);

        for (auto child : root->children)
        {
            copied->children.push_back(cloneTree(child));
        }

        return copied;
    }
};