#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int offset = 1e4;
        int size = 2 * 1e4 + 1;
        int temp = size;
        int height = 0;
        vector<int> ans;

        while (temp != 0)
        {
            temp /= 2;
            height++;
        }

        int treeSize = (int)pow(2, height + 1);
        int trans_idx = treeSize / 2;
        vector<int> tree(treeSize + 1);

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int cnt = query(0, nums[i] + offset, tree, trans_idx);
            ans.push_back(cnt);
            update(nums[i] + offset, 1, tree, trans_idx);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }

    void update(int idx, int val, vector<int> &tree, int trans_idx)
    {
        idx += trans_idx;
        tree[idx] += val;

        while (idx > 1)
        {
            idx /= 2;
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
        }
    }

    int query(int left, int right, vector<int> &tree, int trans_idx)
    {
        int ans = 0;
        left += trans_idx;
        right += trans_idx;

        while (left < right)
        {
            if (left % 2 == 1)
            {
                ans += tree[left];
                left++;
            }

            if (right % 2 == 1)
            {
                right--;
                ans += tree[right];
            }

            left /= 2;
            right /= 2;
        }

        return ans;
    }
};