#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> um;

    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        um[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (um.find(key) == um.end())
            return "";

        if (timestamp < um[key][0].first)
            return "";

        int l = 0, h = um[key].size() - 1;
        while (l <= h)
        {
            int mid = (h - l) / 2 + l;
            int timestampPrev = um[key][mid].first;
            if (timestampPrev == timestamp)
                return um[key][mid].second;
            else if (timestampPrev < timestamp)
                l = mid + 1;
            else
                h = mid - 1;
        }

        return um[key][h].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */