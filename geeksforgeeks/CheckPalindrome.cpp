class Solution
{
public:
    int isPalinUtil(int N, int rev)
    {
        if (N == 0)
            return rev;
        return isPalinUtil(N / 10, rev * 10 + N % 10);
    }
    bool isPalin(int N)
    {

        if (isPalinUtil(N, 0) == N)
            return true;

        return false;
    }
};