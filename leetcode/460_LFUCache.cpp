#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

class LFUCache
{
public:
    unordered_map<int, list<pair<int, int>>> frequencies;
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    int capacity;
    int minF;

    LFUCache(int capacity) : capacity(capacity), minF(0)
    {
    }

    void insertToTail(int key, int freq, int val)
    {
        frequencies[freq].push_back({key, val});
        cache[key] = {freq, --frequencies[freq].end()};
    }

    int get(int key)
    {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;

        int fr = it->second.first;
        auto iter = it->second.second;
        pair<int, int> p = *iter;
        frequencies[fr].erase(iter);
        if (frequencies[fr].empty())
        {
            frequencies.erase(fr);

            if (minF == fr)
                minF++;
        }

        insertToTail(key, fr + 1, p.second);
        return p.second;
    }

    void put(int key, int value)
    {
        if (capacity <= 0)
            return;

        auto it = cache.find(key);
        if (it != cache.end())
        {
            it->second.second->second = value;
            get(key);
            return;
        }

        if (capacity == cache.size())
        {
            cache.erase(frequencies[minF].front().first);
            frequencies[minF].pop_front();

            if (frequencies[minF].empty())
                frequencies.erase(minF);
        }

        minF = 1;
        insertToTail(key, 1, value);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */