#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> shortestDistanceColor(vector<int> &colors, vector<vector<int>> &queries)
    {
        vector<vector<int>> mp(4);
        vector<int> ans;

        for (int i = 0; i < colors.size(); i++)
        {
            mp[colors[i]].push_back(i);
        }

        for (auto query : queries)
        {
            int ind = query[0], color = query[1];

            if (mp[color].size() == 0)
            {
                ans.push_back(-1);
                continue;
            }

            auto &lst = mp[color];
            int pos = binarySearch(lst, ind);
            if (pos == 0)
            {
                ans.push_back(lst[0] - ind);
            }
            else if (pos == lst.size())
            {
                ans.push_back(ind - lst[lst.size() - 1]);
            }
            else
            {
                int can1 = lst[pos] - ind;
                int can2 = ind - lst[pos - 1];
                ans.push_back(min(can1, can2));
            }
        }

        return ans;
    }

    int binarySearch(vector<int> &indList, int target)
    {
        int l = 0, h = indList.size() - 1;
        while (l <= h)
        {
            int mid = (h - l) / 2 + l;
            int val = indList[mid];
            if (target == val)
                return mid;
            else if (target < val)
                h = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};