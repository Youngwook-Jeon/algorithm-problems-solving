#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;

#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define forEachTestCase    \
    long long numTestCase; \
    cin >> numTestCase;    \
    while (numTestCase--)
#define newl '\n'

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void use_file_input_output()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        vector<vector<TreeNode *>> dp(n + 1);
        dp[0].push_back(nullptr);

        for (int num = 1; num <= n; ++num)
        {
            for (int i = 1; i <= num; ++i)
            {
                int j = num - i;
                for (auto left : dp[i - 1])
                {
                    for (auto right : dp[j])
                    {
                        auto newNode = new TreeNode(i, left, scaleNode(right, i));
                        dp[num].push_back(newNode);
                    }
                }
            }
        }

        return dp[n];
    }

    TreeNode *scaleNode(TreeNode *node, int i)
    {
        if (node == nullptr)
            return nullptr;

        TreeNode *scaled = new TreeNode(node->val + i);
        scaled->left = scaleNode(node->left, i);
        scaled->right = scaleNode(node->right, i);
        return scaled;
    }
};
