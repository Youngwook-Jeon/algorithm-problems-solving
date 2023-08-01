#include <vector>
#include <queue>
#include "leetcode_ds.h"
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec
{
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode *encode(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        auto newRoot = new TreeNode(root->val);
        pair<TreeNode *, Node *> head{newRoot, root};

        queue<pair<TreeNode *, Node *>> q;
        q.push(head);

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            auto t = p.first;
            auto n = p.second;

            TreeNode *prevT = nullptr;
            TreeNode *head = prevT;
            for (auto child : n->children)
            {
                auto newT = new TreeNode(child->val);
                if (prevT == nullptr)
                {
                    head = newT;
                }
                else
                {
                    prevT->right = newT;
                }
                prevT = newT;

                q.push({newT, child});
            }

            t->left = head;
        }

        return newRoot;
    }

    // Decodes your binary tree to an n-ary tree.
    Node *decode(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        auto newRoot = new Node(root->val);
        queue<pair<Node *, TreeNode *>> q;
        pair<Node *, TreeNode *> head{newRoot, root};
        q.push(head);

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            auto n = p.first;
            auto t = p.second;

            TreeNode *firstChild = t->left;
            TreeNode *child = firstChild;
            while (child != nullptr)
            {
                auto nextChild = new Node(child->val);
                n->children.push_back(nextChild);
                q.push({nextChild, child});
                child = child->right;
            }
        }

        return newRoot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));