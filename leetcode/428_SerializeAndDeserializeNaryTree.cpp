#include <vector>
#include <queue>
#include <string>
#include <sstream>
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

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(Node *root)
    {
        if (root == nullptr)
            return "";
        queue<Node *> q;
        string ans = "";

        q.push(root);
        ans += to_string(root->val);
        ans += ",null,";
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            for (auto child : node->children)
            {
                q.push(child);
                ans += to_string(child->val);
                ans += ",";
            }
            ans += "null,";
        }
        ans.pop_back();

        return ans;
    }

    // Decodes your encoded data to tree.
    Node *deserialize(string data)
    {
        if (data.size() == 0)
            return nullptr;

        queue<Node *> q1;
        queue<string> q2;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ','))
        {
            q2.push(token);
        }

        auto ans = new Node(stoi(q2.front()));
        q1.push(ans);
        q2.pop();
        q2.pop();

        while (!q2.empty())
        {
            auto node = q1.front();
            q1.pop();
            while (q2.front() != "null")
            {
                auto child = new Node(stoi(q2.front()));
                node->children.push_back(child);
                q2.pop();
                q1.push(child);
            }
            q2.pop();
        }

        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));