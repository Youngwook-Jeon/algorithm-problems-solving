#include <set>
using namespace std;

class MaxStack
{
public:
    int cnt = 0;
    set<pair<int, int>> stk;
    set<pair<int, int>> vals;

    MaxStack()
    {
    }

    void push(int x)
    {
        stk.insert({cnt, x});
        vals.insert({x, cnt});
        cnt++;
    }

    int pop()
    {
        auto p = *stk.rbegin();
        stk.erase(p);
        vals.erase({p.second, p.first});
        return p.second;
    }

    int top()
    {
        return (*stk.rbegin()).second;
    }

    int peekMax()
    {
        return (*vals.rbegin()).first;
    }

    int popMax()
    {
        auto p = *vals.rbegin();
        vals.erase(p);
        stk.erase({p.second, p.first});
        return p.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */