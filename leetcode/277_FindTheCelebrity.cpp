/* The knows API is defined for you.
      bool knows(int a, int b); */
bool knows(int a, int b);

class Solution
{
public:
    int findCelebrity(int n)
    {
        int candidate = 0;
        for (int i = 0; i < n; i++)
        {
            if (knows(candidate, i))
                candidate = i;
        }

        if (!isCelebrity(candidate, n))
            return -1;

        return candidate;
    }

    bool isCelebrity(int candidate, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (candidate == i)
                continue;

            if (knows(candidate, i) || !knows(i, candidate))
                return false;
        }

        return true;
    }
};