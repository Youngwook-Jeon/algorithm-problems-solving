#include <queue>
using namespace std;

class MovingAverage
{
public:
    queue<int> q;
    int size;
    int accum = 0;

    MovingAverage(int size) : size(size)
    {
    }

    double next(int val)
    {
        q.push(val);
        accum += val;
        if (q.size() > size)
        {
            int terminated = q.front();
            q.pop();
            accum -= terminated;
        }

        return ((double)accum) / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */