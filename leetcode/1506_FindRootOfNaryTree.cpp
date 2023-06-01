#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> um;
    int maxHeight = 0;

    // Method 1: Use the def of height of a tree
    Node *findRootV1(vector<Node *> tree)
    {
        Node *ans;
        for (auto node : tree)
        {
            getHeight(node);
        }

        for (auto node : tree)
        {
            if (um[node->val] == maxHeight)
                ans = node;
        }

        return ans;
    }

    int getHeight(Node *node)
    {
        if (um.find(node->val) != um.end())
            return um[node->val];

        int ans = 0;
        for (auto child : node->children)
        {
            ans = max(ans, getHeight(child) + 1);
        }
        um[node->val] = ans;
        maxHeight = max(ans, maxHeight);

        return ans;
    }

    // Method2: The root node is the unique node visited only once!
    Node *findRootV2(vector<Node *> tree)
    {
        int val = 0;
        for (auto node : tree)
        {
            val += node->val;
            for (auto child : node->children)
            {
                val -= child->val;
            }
        }

        for (auto node : tree)
        {
            if (node->val == val)
                return node;
        }

        return nullptr;
    }
};