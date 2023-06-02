#include <vector>
#include <algorithm>
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
    int ans = 0;

    int diameter(Node *root)
    {
        getHeight(root);
        return ans;
    }

    int getHeight(Node *root)
    {
        if (root == nullptr)
            return -1;

        int localRes = 0;
        int first = 0, second = 0;
        for (auto child : root->children)
        {
            int parent = getHeight(child) + 1;
            if (parent > first)
            {
                int temp = first;
                first = parent;
                second = temp;
            }
            else if (parent > second)
            {
                second = parent;
            }
        }
        localRes = first + second;
        ans = max(localRes, ans);

        return first;
    }
};