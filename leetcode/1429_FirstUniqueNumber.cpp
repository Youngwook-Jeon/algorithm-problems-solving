#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class FirstUnique
{
public:
    unordered_map<int, int> um;
    queue<int> q;

    FirstUnique(vector<int> &nums)
    {
        for (int num : nums)
        {
            um[num] += 1;
            if (um[num] == 1)
                q.push(num);
        }
    }

    int showFirstUnique()
    {
        while (!q.empty())
        {
            int num = q.front();
            if (um[num] == 1)
                return num;
            q.pop();
        }

        return -1;
    }

    void add(int value)
    {
        um[value] += 1;
        if (um[value] == 1)
            q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */