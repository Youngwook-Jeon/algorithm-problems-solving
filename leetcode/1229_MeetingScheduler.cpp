#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Interval
{
    int l, h;
    Interval(int l, int h) : l(l), h(h) {}

    bool operator<(const Interval other) const
    {
        return this->l > other.l;
    }
};

class Solution
{
public:
    // 1. Two pointers
    vector<int> minAvailableDuration(vector<vector<int>> &slots1, vector<vector<int>> &slots2, int duration)
    {
        int n = slots1.size();
        int m = slots2.size();
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int i = 0, j = 0;
        vector<int> ans;
        while (i < n && j < m)
        {
            auto p = intersect(slots1[i], slots2[j]);
            if (isSufficient(p, duration))
            {
                ans.push_back(p.first);
                ans.push_back(p.first + duration);
                break;
            }
            else if (slots1[i][1] < slots2[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return ans;
    }

    pair<int, int> intersect(vector<int> &slot1, vector<int> &slot2)
    {
        if (slot1[0] <= slot2[1] && slot2[0] <= slot1[1])
        {
            return make_pair(max(slot1[0], slot2[0]), min(slot1[1], slot2[1]));
        }
        else if (slot2[0] <= slot1[1] && slot1[0] <= slot2[1])
        {
            return make_pair(max(slot1[0], slot2[0]), min(slot1[1], slot2[1]));
        }
        else
        {
            return make_pair(-1, -1);
        }
    }

    bool isSufficient(pair<int, int> p, int duration)
    {
        return p.second - p.first >= duration;
    }

    // 2. Priority queue
    vector<int> minAvailableDuration2(vector<vector<int>> &slots1, vector<vector<int>> &slots2, int duration)
    {
        int n = slots1.size(), m = slots2.size();
        priority_queue<Interval> pq;
        vector<int> ans;

        for (auto slot : slots1)
        {
            if (slot[1] - slot[0] >= duration)
            {
                pq.push({slot[0], slot[1]});
            }
        }

        for (auto slot : slots2)
        {
            if (slot[1] - slot[0] >= duration)
            {
                pq.push({slot[0], slot[1]});
            }
        }

        while (pq.size() > 1)
        {
            auto cur = pq.top();
            pq.pop();
            auto next = pq.top();

            if (cur.h >= next.l + duration)
            {
                ans.push_back(next.l);
                ans.push_back(next.l + duration);
                break;
            }
        }

        return ans;
    }
};